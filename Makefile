# Nom de l'exécutable
TARGET = Demineur

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -std=c++11 -Wall -Wextra

# Fichiers source et en-tête
SRCS = demineur.cpp main.cpp
HDRS = demineur.h

# Générer les noms des fichiers objets à partir des fichiers source
OBJS = $(SRCS:.cpp=.o)

# Règle de compilation
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Règle pour chaque fichier objet
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)
