'''
Given a sentance and two words, find minimum distance b/w these two words in the sentance.

Example : 
sentance : game will mark the first time the venue is hosting an international match since
word 1 :   the
word 2 :   will

Ans : 2 ( 'will' at index 1 and 'the' at index 3)

'''

sentence = input().split()
first_word = input()
second_word = input()

index_of_first_word = float('inf')
index_of_second_word = float('inf')
ans = float('inf')

for i in range(len(sentence)):
    if sentence[i] == first_word:
        index_of_first_word = i
    elif sentence[i] == second_word:
        index_of_second_word = i
    ans = min(ans, abs(index_of_second_word - index_of_first_word))
            
print(ans)
