Word Freak

word freak is split into three parts wordfreak.c, wordparse and the glossary

wordfreak figures out the type of input than takes the appropriate measures to begin parsing

word parse reads char by char stopping at each perceived word then adding it to the glossary

the glossary is a linked list with a special add function that either adds a new word or
increments the count of an existing word in the list if the word already exist in the list
