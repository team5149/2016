BUILD_DIR = .build

COPY_FILES = robot.cmake arm.cmake

.PHONY : all make rebuild


all: 
	@cd $(BUILD_DIR); make;

rebuild:
	# copy non auto-gen'd files out
	@for file in $(COPY_FILES); do \
		cp $(BUILD_DIR)/$$file ./; \
	done
	# remove the build folder
	@rm -rf $(BUILD_DIR)/
	# create the build folder and move files in
	@mkdir $(BUILD_DIR)
	@for file in $(COPY_FILES); do \
		cp $$file $(BUILD_DIR)/; \
		rm $$file; \
	done
	# move to build directory and build the files
	cd $(BUILD_DIR);  \
	cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./arm.cmake robot.cmake .. > /dev/null; \
	make VERBOSE=1; \
	rm -rf CMakeFiles/; \
	rm -rf ./FRCUserProgram; \
	mv ./FRC* ./FRCUserProgram; 

# cmd to pass params through to the build dir
%$@:
	@echo "make command '$@' unknown, passing to $(BUILD_DIR)"
	cd $(BUILD_DIR); make $@
