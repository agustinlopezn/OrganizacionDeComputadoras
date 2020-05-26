from random import randint
from termcolor import cprint  #pip install termcolor
from subprocess import Popen, PIPE
from os import remove #Para eliminar los archivos despues de las pruebas
CANT_ELEM = [5, 10, 50, 100, 1000, 2000]
FILE_NAME_TEST = 'test_'
PATH_TP1 = './tp1'
MIN_NUM = -1000
MAX_NUM = 1000

def applyMergeSortToFile(nameFile, placeTp1):
	'''Aplica el mergesort al archivo de prueba creado y devuelve el resultado'''
	p = Popen([placeTp1, "-i", nameFile], stdout=PIPE, stderr=PIPE)
	output, err = p.communicate() #Devuelve tupla
	return output.decode('ascii') #El output legible

def isSorted(testList):
	'''Verifica si la lista pasada por parametro esta ordenada de menor a mayor'''
	return all(int(testList[j]) <= int(testList[j + 1]) for j in range(len(testList) - 1))

def checkOutput(outputCode, testNumber):
	'''Verifica si el resultado que devuelve mergesort es correcto'''
	error = False
	outputArray = outputCode.split('\n') #Tengo una lista de listas, cada lista contiene una linea del archivo
	for linea in outputArray:
		linea = linea.split() #Tengo una lista con los valores de la linea
		if not isSorted(linea):
			print('Error: el test {} fallo'.format(testNumber))
			error = True
			break

	testText = 'Test ' + str(testNumber) + ': '
	printTest(testText, not error)
	return error

def arrayGenerator(numRows, numElements, minNum, maxNum):
	'''Genera una lista de listas, en la cual cada lista posee diferentes sizes y numeros enteros unicaente'''
	arrays = []
	for _ in range(numRows):
		auxArray = []
		arrayLen = randint(0, numElements) #Asi cada fila tiene distinto size
		for i in range(arrayLen):
			auxArray.append(randint(minNum,maxNum))
		arrays.append(auxArray)
	return arrays #Devuelve el array de arrays con los numeros al azar


def writeTest(testNum, numRows, numElements, minNum, maxNum):
	'''Escribe un archivo de prueba y devuelve el nombre del archivo'''
	file_name = FILE_NAME_TEST + str(testNum)
	array = arrayGenerator(numRows, numElements, minNum, maxNum)
	with open(file_name, 'w') as f:
		for line in array:
			lineText = ' '.join(map(str, line)) + '\n'
			f.write(lineText)

	return file_name

def printTest(output, condition):
	if condition == True: 
		testAnswer = output + 'PASSED\n'
		color = 'green'
	else:
		color = 'red'
		testAnswer = output + 'FAILED\n'
	cprint(testAnswer, color)

def testMaker(path):
	'''Funcion creada para realizar los distintos tests al programa'''
	testsResults = [1,1,1,1,1,1] # 1 si paso la prueba, 0 si no lo hizo
	testNum = 1
	flag = 0
	
	cprint('TESTS:', 'yellow')
	for cant in CANT_ELEM:
		numRows = randint(4,10)
		file_name = writeTest(testNum, numRows, cant, MIN_NUM, MAX_NUM) #Cambiar ultimos valores
		output = applyMergeSortToFile(file_name, path)
		error = checkOutput(output, testNum)
		if error:
			flag = 1 #Para imprimir mensaje luego de correr todos los tests
			testsResults[testNum - 1] = 0 #Para indicar que esa prueba fallo asi no se elimina el archivo
		testNum += 1

	if flag:
		cprint('\nEl programa NO paso todos los tests', 'red')
	else:
		cprint('\nEl programa paso todos los tests', 'green')

	for i in range(1,7):
		testName = FILE_NAME_TEST + str(i)
		if testsResults[i - 1]:
			remove(testName) #Para eliminar los archivos que pasaron la prueba

testMaker(PATH_TP1)