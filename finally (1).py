
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
   if gamepad.get_axis(3)< -0.2:
      arduino.write(ret(-(gamepad.get_axis(3)),'u'))
      if gamepad.get_axis(0)> 0.2:
         arduino.write(ret(gamepad.get_axis(0),'r'))  
      elif gamepad.get_axis(0)<- 0.1:
         arduino.write(ret(-(gamepad.get_axis(0)),'l'))         
         ##################################
      elif gamepad.get_button(6) == True:
         arduino.write(b'o0');
      elif gamepad.get_button(7) == True:
         arduino.write(b'c0');    
      elif gamepad.get_axis(2) > 0.05:
               ##        print "backward"
         arduino.write(ret(gamepad.get_axis(2),'f')) 
      elif gamepad.get_axis(2) < -0.05:
         arduino.write(ret(-(gamepad.get_axis(2)),'b'))
      else:
         arduino.write(b't')
         arduino.write(ret(0,'b'))
         arduino.write(ret(0,'f'))
         arduino.write(ret(0,'l'))
         arduino.write(ret(0,'r'))
  ######################################################       
   elif gamepad.get_axis(3)> 0.1:
      arduino.write(ret(gamepad.get_axis(3),'d'))
      if gamepad.get_axis(0)> 0.2:
         arduino.write(ret(gamepad.get_axis(0),'r'))  
      elif gamepad.get_axis(0)<- 0.1:
         arduino.write(ret(-(gamepad.get_axis(0)),'l'))         
         ##################################
      elif gamepad.get_button(6) == True:
         arduino.write(b'o0');
      elif gamepad.get_button(7) == True:
         arduino.write(b'c0');    
      elif gamepad.get_axis(2) > 0.05:
               ##        print "backward"
         arduino.write(ret(gamepad.get_axis(2),'f')) 
      elif gamepad.get_axis(2) < -0.05:
         arduino.write(ret(-(gamepad.get_axis(2)),'b'))
      else:
         arduino.write(b't')
         arduino.write(ret(0,'b'))
         arduino.write(ret(0,'f'))
         arduino.write(ret(0,'l'))
         arduino.write(ret(0,'r'))
  ##################################################################
   elif gamepad.get_button(6) == True:
      arduino.write(b'o0');
   elif gamepad.get_button(7) == True:
      arduino.write(b'c0');         
   elif gamepad.get_button(0) == True:
      arduino.write(b'w0');
   elif gamepad.get_button(3) == True:
      arduino.write(b's0');   
   elif gamepad.get_axis(0)> 0.2:
      arduino.write(ret(gamepad.get_axis(0),'r')) 
   elif gamepad.get_axis(0)<- 0.1:
      arduino.write(ret(-(gamepad.get_axis(0)),'l'))         
         ##################################
   elif gamepad.get_axis(2) > 0.05:
         ##        print "backward"
      arduino.write(ret(gamepad.get_axis(2),'f')) 
   elif gamepad.get_axis(2) < -0.05:
      arduino.write(ret(-(gamepad.get_axis(2)),'b'))   
         
    #################################

    #################################
    #################################
   else:
##        print('Stop Everything!')
      arduino.write(b'z0')
      arduino.write(b't')
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
    
