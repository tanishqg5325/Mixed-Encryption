OBJS = main.o prime.o vignere.o public_key.o secret_key.o helper.o certificate_authority.o user.o
SOURCE = main.cpp prime.cpp vignere.cpp public_key.cpp secret_key.cpp helper.cpp certificate_authority.cpp user.cpp
OUT = rsa
CXXFLAGS = -lgmpxx -lgmp
CXX = g++

all: $(OUT)

$(OUT): $(OBJS)
		$(CXX) $(OBJS) -o $(OUT) $(CXXFLAGS)

main.o: main.cpp certificate_authority.h user.h
		$(CXX) -c main.cpp -o $@

prime.o: prime.cpp prime.h
		$(CXX) -c prime.cpp -o $@

vignere.o: vignere.cpp vignere.h
		$(CXX) -c vignere.cpp -o $@

public_key.o: public_key.cpp public_key.h helper.h
		$(CXX) -c public_key.cpp -o $@

secret_key.o: secret_key.cpp secret_key.h helper.h
		$(CXX) -c secret_key.cpp -o $@

helper.o: helper.cpp helper.h
		$(CXX) -c helper.cpp -o $@

certificate_authority.o: certificate_authority.cpp certificate_authority.h prime.h public_key.h secret_key.h user.h
		$(CXX) -c certificate_authority.cpp -o $@

user.o: user.cpp user.h public_key.h secret_key.h vignere.h certificate_authority.h
		$(CXX) -c user.cpp -o $@

clean:
		rm *.o
		rm $(OUT)
