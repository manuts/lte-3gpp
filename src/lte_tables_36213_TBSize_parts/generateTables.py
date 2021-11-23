f1 = open("tbSizes1.txt", 'r')
f2 = open("tbSizes2.txt", 'r')

iTbsList = [
"0",
"1",
"2",
"3",
"4",
"5",
"6",
"7",
"8",
"9",
"10",
"11",
"12",
"13",
"14",
"15",
"16",
"17",
"18",
"19",
"20",
"21",
"22",
"23",
"24",
"25",
"26",
"26A",
"27",
"28",
"29",
"30",
"31",
"32",
"32A",
"33",
"33A",
"33B",
"34",
"34A",
"35",
"36",
"37A",
"37"
]

tbSizeList = [];
numRows = len(iTbsList)
for i in range(numRows):
	tbSizeList.append([])

lineCount1 = 0;
lineCount2 = 0;

for line in f1:
	lineCount1 = lineCount1 + 1
	words=line.split(',')
	assert(len(words)==11)
	if words[0] in iTbsList:
		loc=iTbsList.index(words[0])
		for iii in range(10):
			tbSizeList[loc].append(words[iii+1].strip())
	else:
		assert(0);


for line in f2:
	lineCount2 = lineCount2 + 1
	words=line.split(',')
	assert(len(words)==11)
	if words[0] in iTbsList:
		loc=iTbsList.index(words[0])
		for iii in range(10):
			tbSizeList[loc].append(words[iii+1].strip())
	else:
		assert(0, "Error");

assert(len(tbSizeList) == 44)
stringList = [];
for iii in range(len(tbSizeList)):
	itbsWord="lte::enums::i_tbs::i" + iTbsList[iii]
	string="{" + itbsWord.ljust(24) + ", {"
	assert(len(tbSizeList[iii]) == 110)
	for jjj in range(109):
		word=tbSizeList[iii][jjj].rjust(8)
		string=string+word+", "
	word=tbSizeList[iii][109].rjust(8)
	string=string+word+"   }}"

	stringList.append(string)

f3 = open("tbSizes.txt", 'w')
for iii in range(len(stringList)):
	f3.write(stringList[iii]+",\n")

for jjj in range(110):
	word=str(jjj+1).rjust(10)
	f3.write(word)

f1.close()
f2.close()
f3.close()