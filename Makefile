# Default target executed when no arguments are given to make.
default_target: rebuild

.PHONY : rebuild
rebuild:
	make clean
	make build
	make run

.PHONY : build
build:
	@echo "Build application"
	cmake -S . --preset=eb-release
	@echo "Create executable"
	cd ./build/eb-release; make

.PHONY : run
run:
	@echo "Running application"
	cd ./build/eb-release; ./Eb

.PHONY : clean
clean:
	@echo "Remove current build"
	rm -rf ./build