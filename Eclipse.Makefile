
all:	
	cd build; make 

clean:
	cd build; make clean

build:
	test -d build || mkdir -p build
	cd build; cmake ..
	mkdir -p comstack/unittest/build
	cd comstack/unittest/build; cmake ..

cleanup:
	rm -r build || true
	rm -rf  build

upload:
	cd build; make upload
			
test:
	cd comstack/unittest/build; make; ../test-run
	
