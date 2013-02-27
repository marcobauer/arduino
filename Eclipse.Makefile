
all:	
	cd build; make 

clean:
	cd build; make clean

build:
	test -d build || mkdir -p build
	cd build; cmake ..
#	mkdir -p comstack/unittest/build
#	cd comstack/unittest/build; cmake ..

cleanup:
	rm -rf 	build || true
#	rm -rf  comstack/unittest/build || true

upload:
	cd build; make upload
			
test:
	rm comstack/unittest/test-run || true
#	cd comstack/unittest/build; make
#	cd comstack/unittest/build; ../test-run
