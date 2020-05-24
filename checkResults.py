FILE_NAME_ANSW = 'testAnswer_'
FILE_NAME_RESULT = 'output_'
FORMAT = '.txt'
def checkOutputs(numOfFilesToCheck):
	error = False
	for i in range(numOfFilesToCheck):
		answerFile = FILE_NAME_ANSW + str(i + 1) + FORMAT #Nombre de la respuesta
		outputFile = FILE_NAME_RESULT + str(i+1) + FORMAT #Nombre del resultado

		with open(answerFile, 'r') as answer, open(outputFile, 'r') as output:
			for answLine, outLine in zip(answer, output):
				answLine = answLine.rstrip("\n")
				outLine = outLine.rstrip("\n")
				if outLine != answLine:
					print('Error: el archivo {} dio incorrecto'.format(i + 1))
					error = True
					break
		if not error:
			print('Todos los resultados son correctos')

checkOutputs(5)