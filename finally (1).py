
# now starting from line 69 we want to applay this to the whole program

import pygame
import time
import serial

arduino = serial.Serial("COM3",9600,timeout=.1)
time.sleep(2)


pygame.init()
pygame.joystick.init()
gamepad = pygame.joystick.Joystick(0)
gamepad.init()
############# The function that return the value formated as we want in the arduino serial ############### 
def ret(acc,sym):
   x=acc*255.0
   z=sym+str(int(x))
   y = z.encode()
   return y 
######################################endof the function #################################################   
while pygame.event.poll().type != pygame.QUIT:
   
    if gamepad.get_button(6) and gamepad.get_button(3):
##        print "upwith"
        arduino.write(b't')
    elif gamepad.get_button(6) and gamepad.get_button(0):
##        print 'downwith' 
    #elif gamepad.get_button(0) == True:
###        print('down')
        #arduino.write(b'd')
       
        '''
    elif gamepad.get_button(1) == True:
        arduino.write(b'x')
        print('narrowRight')
    elif gamepad.get_button(2) == True:
        arduino.write(b'l')
        print('narrowLeft')
        '''
    elif gamepad.get_button(3) == True:
        arduino.write(b'u')
##        print('up')
        '''
    elif gamepad.get_button(4)==True:
        print('backward')
        arduino.write(b'b')
    elif gamepad.get_button(5)==True:
        print('forward')
        arduino.write(b'f')
        '''
    #################################        
    elif gamepad.get_button(6)==True:
##        print('arm')
        arduino.write(b'p')
    elif gamepad.get_button(7)==True:
##        print('arm')
        arduino.write(b'i')
        
    #################################
    elif gamepad.get_axis(4) < -0.9:
##        print "left"
        arduino.write(b'l ')
    elif gamepad.get_axis(4) > 0.9:
##        print "right"
        arduino.write(b'r')          
    ##################################
    elif gamepad.get_axis(1) < -0.9:
##        print "forward"
        arduino.write(b'f')
    elif gamepad.get_axis(1) > 0.9:
##        print "backward"
        arduino.write(b'b')
    elif gamepad.get_axis(2) > 0.05:
##        print "backward"
        arduino.write(ret(gamepad.get_axis(2),'f')) 
    elif gamepad.get_axis(2) < -0.05:
        arduino.write(ret(-(gamepad.get_axis(2)),'b'))   
       
    #################################
    elif gamepad.get_hat(0) == (0, -1):
        arduino.write(b'g')
##        print('camUp')
    elif gamepad.get_hat(0) == (0, 1):
        arduino.write(b'j')
##        print('camDown')
    #################################
    #################################
    else:
##        print('Stop Everything!')
        arduino.write(b'r0')
    ##################################
    '''
    elif gamepad.get_hat(0) == (-1, 0):
        #print('cameraLeft')
        arduino.write(b'4')
    elif gamepad.get_hat(0) == (1, 0):
        arduino.write(b'6')
        print('cameraRight')
        '''
    ####################################
    time.sleep(0.1)
