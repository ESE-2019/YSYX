.PHONY: run

COLOR_RED   = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_NONE  = \033[0m

run:
	@make -C riscv-tests-am run ARCH=$(ARCH)
	@make -C cpu-tests run ARCH=$(ARCH)
	@make -C microbench run ARCH=$(ARCH) mainargs=test
	@echo "+--------------+"
	@echo "| TEST  RESULT |"
	@echo "+--------------+"
	@cat ./riscv-tests-am/.result
	@rm ./riscv-tests-am/.result
	@cat ./cpu-tests/.result
	@rm ./cpu-tests/.result
	
clean:
	make -C riscv-tests-am clean
	make -C cpu-tests clean
	make -C microbench clean
