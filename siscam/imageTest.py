from pymba import *
import os
import numpy as np
import time
from png_writer import PngWriter
i=0
time0 = time.time()
vimba = Vimba()
vimba.startup()
cameraIds = vimba.getCameraIds()
cam0 = vimba.getCamera(cameraIds[0])
cam0.openCamera()
cam0.AcquisitionMode = 'Continuous'
while 1:
	frame0 = cam0.getFrame()
	frame0.announceFrame()
	cam0.startCapture()
	frame0.queueFrameCapture()
	cam0.runFeatureCommand('AcquisitionStart')
	time.sleep(1.1/10.0)
	cam0.runFeatureCommand('AcquisitionStop')
	acqTime = time.time()
	cam0.endCapture()
	print "acquired at "  + str(acqTime-time0)
	imdNp = np.ndarray(buffer = frame0.getBufferByteData(), dtype = np.uint8, shape = (frame0.height,frame0.width))

	PngWriter(os.path.join(os.getcwd(),'testImage.png'),imdNp, bitdepth = 8)
	writeTime = time.time()
	cam0.revokeAllFrames()
	i+=1
	
	if i == 100:

		print "Acquired 10 images"
		break
cam0.closeCamera()
		