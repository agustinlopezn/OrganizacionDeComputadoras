from random import randint
FORMATO = '.txt'
CANT_ELEM = [5, 10, 50, 100, 1000]

def arrayGenerator(numRows, numElements, minNum, maxNum):
	arrays = []
	for _ in range(numRows):
		auxArray = []
		arrayLen = randint(0, numElements) #Asi cada fila tiene distinto size
		for i in range(arrayLen):
			auxArray.append(randint(minNum,maxNum))
		arrays.append(auxArray)
	return arrays #Devuelve el array de arrays con los numeros al azar


def writeTest(testNum, numRows, numElements, minNum, maxNum):
	file_name = 'test_' + str(testNum) + FORMATO
	array = arrayGenerator(numRows, numElements, minNum, maxNum)
	with open(file_name, 'w') as f:
		for line in array:
			lineText = ' '.join(map(str, line)) + '\n'
			f.write(lineText)

def testMaker():
	testNum = 1
	for cant in CANT_ELEM:
		numRows = randint(4,10)
		writeTest(testNum, numRows, cant, -5, 20) #Cambiar min y max despues
		testNum += 1


testMaker()