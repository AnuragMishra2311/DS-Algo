'''

The program must accept a string S a character ch and an integer k  as the input. 
The string is said to be valid only if the character CH is consecutively repeated for at most K times. 
The program must print the minimum number of characters to be removed from S to become a valid string as the output.

Input :  abccccddeee c 2
output : 2

remove 2 c's from 4 consecutive c's.

'''


s, ch, times = input().split()
times = int(times)

i = 0
count_deleted = 0
count_continous = 0

while i < len(s):
    while (i < len(s) and s[i] == ch and count_continous < times):
        i += 1
        count_continous += 1
        
    count_continous = 0
    while (i < len(s) and s[i] == ch):
        count_deleted += 1
        i += 1
        
    i += 1
    
print(count_deleted)
        
        
    
    
