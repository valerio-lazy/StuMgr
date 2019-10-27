SrcFiles=$(wildcard *.cpp)
ObjFiles=$(patsubst %.cpp, %.o, $(SrcFiles))
AppFile=a.out

all:$(AppFile)


$(AppFile):$(ObjFiles)
	g++ $^ -o $@ 

%.o:%.cpp
	g++ -c $^ -std=c++11

clean:
	rm -f $(AppFile) $(ObjFiles)
