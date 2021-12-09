###############################################################################
# (c) 2005-2015 Copyright, Real-Time Innovations.  All rights reserved.       #
# No duplications, whole or partial, manual or electronic, may be made        #
# without express written permission.  Any such copies, or revisions thereof, #
# must display this notice unaltered.                                         #
# This code contains trade secrets of Real-Time Innovations, Inc.             #
###############################################################################

from sys import path as sysPath
from os import path as osPath
import time
import ctypes
import argparse
import rticonnextdds_connector as rti
import random
import struct
import math
from tkinter import *
import numpy as np
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2Tk
from matplotlib.figure import Figure
from threading import Timer
import signal
import sys
filepath = osPath.dirname(osPath.realpath(__file__))

def signal_handler(sig, frame):
    print("exit from ctrl-c")
    sys.exit(0)

class RepeatedTimer(object):
    def __init__(self, interval, function, *args, **kwargs):
        self._timer     = None
        self.interval   = interval
        self.function   = function
        self.args       = args
        self.kwargs     = kwargs
        self.is_running = False
        self.start()

    def _run(self):
        self.is_running = False
        self.start()
        self.function(*self.args, **self.kwargs)

    def start(self):
        if not self.is_running:
            self._timer = Timer(self.interval, self._run)
            self._timer.start()
            self.is_running = True

    def stop(self):
        self._timer.cancel()
        self.is_running = False


class Model(object):
    def __init__(self):
        self.maxXres = 50
        self.perfCount = 0
        self.plotcx = np.array([0])
        self.plotcyRT = np.array([0])
        self.plotcyPQ = np.array([0])
        self.plotcyTL = np.array([0])
        self.plotcySQ = np.array([0])
        self.showRef = 0
        self.showlatRT = True
        self.showlatPQ = True
        self.showlatSQ = True
        self.showlatTL = True

    def setRTenable(self, graphOn):
        if graphOn == True:
            self.showlatRT = True
        else:
            self.showlatRT = False

    def setPQenable(self, graphOn):
        if graphOn == True:
            self.showlatPQ = True
        else:
            self.showlatPQ = False

    def setTLenable(self, graphOn):
        if graphOn == True:
            self.showlatTL = True
        else:
            self.showlatTL = False

    def setSQenable(self, graphOn):
        if graphOn == True:
            self.showlatSQ = True
        else:
            self.showlatSQ = False

    def time_class_draw_chart(self):
        try:
            perfIn.wait(500)
        except rti.TimeoutError:
            print("No Data");
            subPerfStatus.set("VidSub: No Data")
            pass
        else:
            perfIn.take()
            for sample in perfIn.samples.valid_data_iter:
                subPerfStatus.set("VidSub: Data OK")
                # Mean latency in [0]PQ and [2]SQ are usable as-is
                latencies = sample.get_dictionary('latency_mean')
                self.plotcyPQ = np.append(self.plotcyPQ, float(latencies[0])/1000)
                self.plotcySQ = np.append(self.plotcySQ, float(latencies[2])/1000)
                sq_latency = latencies[2]
                
                # RT latency is derived from: most-recent timestamps
                tstampchain = sample.get_dictionary('timestamps_last')
                print("{},{}".format(tstampchain, sample.info["reception_timestamp"]))
                rt_latency = sample.info["reception_timestamp"] - tstampchain[1]
                self.plotcyRT = np.append(self.plotcyRT, float(rt_latency)/1000)

                # Transport latency                              
                self.plotcyTL = np.append(self.plotcyTL, float(rt_latency - sq_latency)/2000)

                # self.plotcy = np.append(self.plotcy, sample.get_number('data_count'))
                # self.altcy = np.append(self.altcy, sample.get_number('samples_dropped'))
                self.plotcx = np.append(self.plotcx, self.perfCount)
                self.perfCount = self.perfCount + 1

            trimqty = self.plotcyRT.size - self.maxXres
            if trimqty > 0:
                trimIdx = np.arange(0, trimqty, 1)
                self.plotcyPQ = np.delete(self.plotcyPQ, trimIdx)
                self.plotcyTL = np.delete(self.plotcyTL, trimIdx) 
                self.plotcySQ = np.delete(self.plotcySQ, trimIdx)
                self.plotcyRT = np.delete(self.plotcyRT, trimIdx)
                self.plotcx = np.delete(self.plotcx, trimIdx)

            gCnt = 0
            if self.showlatRT == True:
                gCnt += 1
            if self.showlatPQ == True:
                gCnt += 1
            if self.showlatTL == True:
                gCnt += 1
            if self.showlatSQ == True:
                gCnt += 1

            fig.clear()
            tCnt = 1
            if self.showlatRT == True:
                self.ch1 = fig.add_subplot(gCnt, 1, tCnt, yscale = 'linear' )
                self.ch1.set_ylabel('RoundTrip')
                self.ch1.plot(self.plotcx, self.plotcyRT)
                tCnt += 1

            if self.showlatPQ == True:
                self.ch2 = fig.add_subplot(gCnt, 1, tCnt, yscale = 'linear' )
                self.ch2.set_ylabel('PubQueue')
                self.ch2.plot(self.plotcx, self.plotcyPQ)
                tCnt += 1

            if self.showlatTL == True:
                self.ch3 = fig.add_subplot(gCnt, 1, tCnt, yscale = 'linear' )
                self.ch3.set_ylabel('Transport')
                self.ch3.plot(self.plotcx, self.plotcyTL)
                tCnt += 1

            if self.showlatSQ == True:
                self.ch4 = fig.add_subplot(gCnt, 1, tCnt, yscale = 'linear' )
                self.ch4.set_ylabel('SubQueue')
                self.ch4.plot(self.plotcx, self.plotcySQ)
                tCnt += 1

            fig.subplots_adjust(hspace=0.4)
            canvas.draw_idle()


def draw_chart():
    fig.clear()
    fig.add_subplot(111).plot(np.random.randint(1,10,5), np.random.randint(10,20,5)) #generate random x/y
    canvas.draw_idle()

def RTButtonCallback():
    if RTBtn['relief'] == SUNKEN:
        RTBtn['relief'] = RAISED
        model.setRTenable(False)
    else:
        RTBtn['relief'] = SUNKEN
        model.setRTenable(True)

def PQButtonCallback():
    if PQBtn['relief'] == SUNKEN:
        PQBtn['relief'] = RAISED
        model.setPQenable(False)
    else:
        PQBtn['relief'] = SUNKEN
        model.setPQenable(True)

def TLButtonCallback():
    if TLBtn['relief'] == SUNKEN:
        TLBtn['relief'] = RAISED
        model.setTLenable(False)
    else:
        TLBtn['relief'] = SUNKEN
        model.setTLenable(True)

def SQButtonCallback():
    if SQBtn['relief'] == SUNKEN:
        SQBtn['relief'] = RAISED
        model.setSQenable(False)
    else:
        SQBtn['relief'] = SUNKEN
        model.setSQenable(True)

def sampSizeButtonCallback():
    packetsPerSample = sampSizeSetValue.get()
    print("IN sampSizeButtonCallback ({})".format(packetsPerSample))
    controlOut.instance.set_number('content_type', 2)
    controlOut.instance.set_number('packets_per_sample', packetsPerSample)
    controlOut.write()


# RTI Connector is used to control the video pub and get performance data from video sub
with rti.open_connector(
    config_name = "MyParticipantLibrary::VidMonCtl", 
    url=filepath + "/ccvstream_types.xml") as connector:

    controlOut = connector.get_output("vidControlPub::vidControlWriter")
    perfIn = connector.get_input("vidPerfSub::vidPerfReader")

    root = Tk()
    root.title('Video Streaming Performance')
    root.geometry('800x600')

    # Build the UI as a paned window hierarchy --------------
    # top-level is horizontal (buttons on left, graph on right)
    m1 = PanedWindow(orient = HORIZONTAL)
    m1.pack(fill = BOTH, expand = 1)

    # left side has a container of vertically-stacked containers
    l1 = PanedWindow(m1, orient = VERTICAL)
    m1.add(l1)

    # containers within left side have horizontally arranged elements
    # pub and sub status indicators
    l2a = PanedWindow(l1, orient = HORIZONTAL)
    l1.add(l2a)
    pubCtrlStatus = StringVar()
    pubLabel = Label(l2a, textvariable = pubCtrlStatus, relief = GROOVE)
    pubCtrlStatus.set("VidPub:      ")
    l2a.add(pubLabel)
    subPerfStatus = StringVar()
    subLabel = Label(l2a, textvariable = subPerfStatus, relief = GROOVE)
    subPerfStatus.set("VidSub: startup")
    l2a.add(subLabel)

    # data sample send size
    l2f = PanedWindow(l1, orient = HORIZONTAL)
    l1.add(l2f)
    sampSizeBtn = Button(l2f, text = 'setSize', command = sampSizeButtonCallback, width = 10)
    l2f.add(sampSizeBtn)
    sampSizeSetValue = IntVar()
    sampSizeSlider = Scale(l2f, from_ = 1, to = 100, variable = sampSizeSetValue, orient = HORIZONTAL)
    l2f.add(sampSizeSlider)

    # block diagram image for latency paths
    l2z = PanedWindow(l1, orient = HORIZONTAL)
    l1.add(l2z)
    blkdiag = PhotoImage(file='testblock.png')
    bkdLabel = Label(l2z, image = blkdiag, relief = GROOVE)
    l2z.add(bkdLabel)

    # Button enablers for latency graphs
    l2y = PanedWindow(l1, orient = HORIZONTAL)
    l1.add(l2y)
    RTBtn = Button(l2y, text = 'RT', command = RTButtonCallback, width = 3, relief = SUNKEN)
    l2y.add(RTBtn)
    PQBtn = Button(l2y, text = 'PQ', command = PQButtonCallback, width = 3, relief = SUNKEN)
    l2y.add(PQBtn)
    TLBtn = Button(l2y, text = 'TL', command = TLButtonCallback, width = 3, relief = SUNKEN)
    l2y.add(TLBtn)
    SQBtn = Button(l2y, text = 'SQ', command = SQButtonCallback, width = 3, relief = SUNKEN)
    l2y.add(SQBtn)
    genFillString = StringVar()
    gfLabel = Label(l2y, textvariable = genFillString, relief = GROOVE)
    genFillString.set("  ")
    l2y.add(gfLabel)

    # text field for the bottom left
    l2g = PanedWindow(l1, orient = HORIZONTAL)
    l1.add(l2g)
    textField = Text(l2g, width = 24)
    l2g.add(textField)


    m2 = PanedWindow(m1, orient = HORIZONTAL)
    m1.add(m2)

    fig = Figure(figsize=(5, 4), dpi=100)
    canvas = FigureCanvasTkAgg(fig, master=m2)  # A tk.DrawingArea.
    canvas.get_tk_widget().pack(side=TOP, fill=BOTH, expand=1)
    toolbar = NavigationToolbar2Tk(canvas, m2)

    Button(root,text="Draw",command=draw_chart).pack()

    signal.signal(signal.SIGINT, signal_handler)

    model = Model()
    rt = RepeatedTimer(1, model.time_class_draw_chart) 

    try:
        root.mainloop()
    finally:
        rt.stop()
