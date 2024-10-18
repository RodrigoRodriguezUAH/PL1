##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PL1
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/pegar/Desktop/EDD/PL/PL1
ProjectPath            :=C:/Users/pegar/Desktop/EDD/PL/PL1
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=pegar
Date                   :=10/18/2024
CodeLitePath           :="C:/Users/pegar/Desktop/Programas/Programas para la Uni/CodeLite/codelite-amd64-17.0.0/codelite"
LinkerName             :=C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="PL1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/msys64/mingw64/bin/ar.exe -r
CXX      := C:/msys64/mingw64/bin/g++.exe
CC       := C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Users\pegar\Desktop\Programas\Programas para la Uni\CodeLite\codelite-amd64-17.0.0\codelite
Objects0=$(IntermediateDirectory)/PL1_PL1_Cola.cpp$(ObjectSuffix) $(IntermediateDirectory)/PL1_PL1_Gestor.cpp$(ObjectSuffix) $(IntermediateDirectory)/PL1_PL1_NodoPila.cpp$(ObjectSuffix) $(IntermediateDirectory)/PL1_PL1_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/PL1_PL1_Lista.cpp$(ObjectSuffix) $(IntermediateDirectory)/PL1_PL1_NodoLista.cpp$(ObjectSuffix) $(IntermediateDirectory)/PL1_PL1_Proceso.cpp$(ObjectSuffix) $(IntermediateDirectory)/PL1_PL1_NodoCola.cpp$(ObjectSuffix) $(IntermediateDirectory)/PL1_PL1_Pila.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/PL1_PL1_Cola.cpp$(ObjectSuffix): PL1/PL1/Cola.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/pegar/Desktop/EDD/PL/PL1/PL1/PL1/Cola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PL1_PL1_Cola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PL1_PL1_Cola.cpp$(PreprocessSuffix): PL1/PL1/Cola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PL1_PL1_Cola.cpp$(PreprocessSuffix) PL1/PL1/Cola.cpp

$(IntermediateDirectory)/PL1_PL1_Gestor.cpp$(ObjectSuffix): PL1/PL1/Gestor.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/pegar/Desktop/EDD/PL/PL1/PL1/PL1/Gestor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PL1_PL1_Gestor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PL1_PL1_Gestor.cpp$(PreprocessSuffix): PL1/PL1/Gestor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PL1_PL1_Gestor.cpp$(PreprocessSuffix) PL1/PL1/Gestor.cpp

$(IntermediateDirectory)/PL1_PL1_NodoPila.cpp$(ObjectSuffix): PL1/PL1/NodoPila.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/pegar/Desktop/EDD/PL/PL1/PL1/PL1/NodoPila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PL1_PL1_NodoPila.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PL1_PL1_NodoPila.cpp$(PreprocessSuffix): PL1/PL1/NodoPila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PL1_PL1_NodoPila.cpp$(PreprocessSuffix) PL1/PL1/NodoPila.cpp

$(IntermediateDirectory)/PL1_PL1_main.cpp$(ObjectSuffix): PL1/PL1/main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/pegar/Desktop/EDD/PL/PL1/PL1/PL1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PL1_PL1_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PL1_PL1_main.cpp$(PreprocessSuffix): PL1/PL1/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PL1_PL1_main.cpp$(PreprocessSuffix) PL1/PL1/main.cpp

$(IntermediateDirectory)/PL1_PL1_Lista.cpp$(ObjectSuffix): PL1/PL1/Lista.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/pegar/Desktop/EDD/PL/PL1/PL1/PL1/Lista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PL1_PL1_Lista.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PL1_PL1_Lista.cpp$(PreprocessSuffix): PL1/PL1/Lista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PL1_PL1_Lista.cpp$(PreprocessSuffix) PL1/PL1/Lista.cpp

$(IntermediateDirectory)/PL1_PL1_NodoLista.cpp$(ObjectSuffix): PL1/PL1/NodoLista.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/pegar/Desktop/EDD/PL/PL1/PL1/PL1/NodoLista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PL1_PL1_NodoLista.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PL1_PL1_NodoLista.cpp$(PreprocessSuffix): PL1/PL1/NodoLista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PL1_PL1_NodoLista.cpp$(PreprocessSuffix) PL1/PL1/NodoLista.cpp

$(IntermediateDirectory)/PL1_PL1_Proceso.cpp$(ObjectSuffix): PL1/PL1/Proceso.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/pegar/Desktop/EDD/PL/PL1/PL1/PL1/Proceso.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PL1_PL1_Proceso.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PL1_PL1_Proceso.cpp$(PreprocessSuffix): PL1/PL1/Proceso.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PL1_PL1_Proceso.cpp$(PreprocessSuffix) PL1/PL1/Proceso.cpp

$(IntermediateDirectory)/PL1_PL1_NodoCola.cpp$(ObjectSuffix): PL1/PL1/NodoCola.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/pegar/Desktop/EDD/PL/PL1/PL1/PL1/NodoCola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PL1_PL1_NodoCola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PL1_PL1_NodoCola.cpp$(PreprocessSuffix): PL1/PL1/NodoCola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PL1_PL1_NodoCola.cpp$(PreprocessSuffix) PL1/PL1/NodoCola.cpp

$(IntermediateDirectory)/PL1_PL1_Pila.cpp$(ObjectSuffix): PL1/PL1/Pila.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/pegar/Desktop/EDD/PL/PL1/PL1/PL1/Pila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PL1_PL1_Pila.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PL1_PL1_Pila.cpp$(PreprocessSuffix): PL1/PL1/Pila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PL1_PL1_Pila.cpp$(PreprocessSuffix) PL1/PL1/Pila.cpp

##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/

