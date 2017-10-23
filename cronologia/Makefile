SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o
	$(CXX) -Wall -g -o $(BIN)/pruebacronologia $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o

$(OBJ)/Cronologia.o : $(INC)/Cronologia.h $(SRC)/Cronologia.cpp $(INC)/FechaHistorica.h $(INC)/VectorDinamico.h $(SRC)/VectorDinamico.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp $(SRC)/VectorDinamico.cpp
	
$(OBJ)/FechaHistorica.o : $(INC)/FechaHistorica.h $(SRC)/FechaHistorica.cpp $(INC)/VectorDinamico.h $(INC)/VectorDinamico.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) $(SRC)/FechaHistorica.cpp -o $(OBJ)/FechaHistorica.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
