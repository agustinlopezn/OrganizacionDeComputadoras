FILE_NAME_RESULT = 'output_'
FORMAT = '.txt'

def isSorted(testList):
	return all(int(testList[j]) <= int(testList[j + 1]) for j in range(len(testList) - 1))

def checkOutputs(numOfFilesToCheck):
	error = False
	for i in range(numOfFilesToCheck):
		outputFile = FILE_NAME_RESULT + str(i + 1) + FORMAT #Nombre del resultado
		with open(outputFile,'r') as output:
			for outLine in output:
				outLine = outLine.rstrip("\n")
				outlineArray = outLine.split() #Lo separo en un array de strings
				if not isSorted(outlineArray):
					print('Error: el archivo {} dio incorrecto'.format(i + 1))
					error = True
					break

		if not error:
			print('Todos los resultados son correctos')

checkOutputs(5)