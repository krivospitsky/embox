#include <gen_board_conf.h>
#include <stm32.h>

struct uart_conf uarts[] = {
 	[1] = {
 		.status = DISABLED,
		.name = "USART1",
		.dev = {
			.irqs = {
				VAL("", 37),
			},
			.pins = {
				PIN("TX", PA, PIN_9, AF7),
				PIN("RX", PA, PIN_10, AF7),
			},
			.clocks = {
				VAL("TX",   CLK_GPIOA),
				VAL("RX",   CLK_GPIOA),
				VAL("UART", CLK_USART1),
			}
		},
		.baudrate = 115200,
	},
	[2] = {
		.status = ENABLED,
		.name = "USART2",
		.dev = {
			.irqs = {
				VAL("", 38),
			},
			.pins = {
				PIN("TX", PA, PIN_2, AF7),
				PIN("RX", PA, PIN_3, AF7),
			},
			.clocks = {
				VAL("TX",   CLK_GPIOA),
				VAL("RX",   CLK_GPIOA),
				VAL("UART", CLK_USART2),
			}
		},
		.baudrate = 115200,
	},
    [3] = {
		.status = DISABLED,
		.name = "USART3",
		.dev = {
			.irqs = {
				VAL("", 39),
			},
			.pins = {
				PIN("TX", PD, PIN_8, AF7),
				PIN("RX", PD, PIN_9, AF7),
			},
			.clocks = {
				VAL("TX",   CLK_GPIOD),
				VAL("RX",   CLK_GPIOD),
				VAL("UART", CLK_USART3),
			}
		},
		.baudrate = 115200,
	},
	[6] = {
		.status = DISABLED,
		.name = "USART6",
		.dev = {
			.irqs = {
				VAL("", 71),
			},
			.pins = {
				PIN("TX", PC, PIN_6, AF8),
				PIN("RX", PC, PIN_7, AF8),
			},
			.clocks = {
				VAL("TX",   CLK_GPIOC),
				VAL("RX",   CLK_GPIOC),
				VAL("UART", CLK_USART6),
			}
		},
		.baudrate = 115200,
	},
};

struct led_conf leds[] = {
	[0] = {
		.name = "LED1",
		.port = VAL("", GPIO_PORT_A),
		.pin = VAL("", 5),
	},
};

struct spi_conf spis[] = {
	[1] = {
		.status = ENABLED,
		.name = "SPI1",
		.dev = {
			.pins = {
				PIN("SCK",  PA, PIN_5, AF5),
				PIN("MISO", PA, PIN_6, AF5),
				PIN("MOSI", PA, PIN_7, AF5),
				PIN("CS",   PD, PIN_14, NOAF),
			},
			.clocks = {
				VAL("SCK",  CLK_GPIOA),
				VAL("MISO", CLK_GPIOA),
				VAL("MOSI", CLK_GPIOA),
				VAL("CS",   CLK_GPIOD),
				VAL("SPI",  CLK_SPI1),
			}
		},
	},

};


EXPORT_CONFIG(UART(uarts), LED(leds), SPI(spis))
