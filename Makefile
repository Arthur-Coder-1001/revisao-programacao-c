CC := gcc
CFLAGS := -std=c17 -Wall -Wextra -Werror -pedantic -Iinclude
LDLIBS := -lm
BUILD_DIR := build

.PHONY: all build run demo test clean

all: build

build: $(BUILD_DIR)/monitor

$(BUILD_DIR)/monitor: src/main.c src/monitor.c include/monitor.h
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) src/main.c src/monitor.c -o $@

run: build
	./$(BUILD_DIR)/monitor

demo: build
	@if [ "$(ETAPA)" = "03" ]; then \
		$(CC) $(CFLAGS) src/demo_lista.c src/monitor.c $(LDLIBS) -o $(BUILD_DIR)/demo_03; \
		./$(BUILD_DIR)/demo_03; \
	elif [ "$(ETAPA)" = "04" ]; then \
		$(CC) $(CFLAGS) src/demo_arquivo.c src/monitor.c $(LDLIBS) -o $(BUILD_DIR)/demo_04; \
		./$(BUILD_DIR)/demo_04; \
	else \
		echo "Informe a etapa: make demo ETAPA=03 ou ETAPA=04"; \
		exit 2; \
	fi

test: build
	@if [ -z "$(ETAPA)" ]; then \
		echo "Informe a etapa: make test ETAPA=01, 02, 03 ou 04"; \
		exit 2; \
	fi
	@set -e; \
	case "$(ETAPA)" in \
		01) testes="01" ;; \
		02) testes="01 02" ;; \
		03) testes="01 02 03" ;; \
		04) testes="01 02 03 04" ;; \
		*) echo "Etapa desconhecida: $(ETAPA)"; exit 2 ;; \
	esac; \
	for numero in $$testes; do \
		$(CC) $(CFLAGS) tests/test_$$numero.c src/monitor.c $(LDLIBS) -o $(BUILD_DIR)/test_$$numero; \
		./$(BUILD_DIR)/test_$$numero; \
	done
	@if [ "$(ETAPA)" = "03" ] || [ "$(ETAPA)" = "04" ]; then \
		./$(BUILD_DIR)/monitor > $(BUILD_DIR)/saida.txt; \
		grep -Fx "Sensor: TMP-01" $(BUILD_DIR)/saida.txt; \
		grep -Fx "Leituras aceitas: 4" $(BUILD_DIR)/saida.txt; \
		grep -Fx "Minima: 23.8 C" $(BUILD_DIR)/saida.txt; \
		grep -Fx "Maxima: 80.0 C" $(BUILD_DIR)/saida.txt; \
		grep -Fx "Media: 38.3 C" $(BUILD_DIR)/saida.txt; \
		grep -Fx "Estado: NORMAL" $(BUILD_DIR)/saida.txt; \
	fi

clean:
	rm -rf $(BUILD_DIR)
