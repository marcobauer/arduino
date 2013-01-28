
all:	
	cd build; make 

clean:
	cd build; make clean

create_build:
	test -d build || mkdir -p build
	cd build; cmake ..

remove_build:
	rm -rf  build

upload:
	cd build; make upload
			