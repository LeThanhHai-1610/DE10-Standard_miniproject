	niosiisystem u0 (
		.clk_clk       (<connected-to-clk_clk>),       //       clk.clk
		.reset_reset   (<connected-to-reset_reset>),   //     reset.reset
		.sdram_clk_clk (<connected-to-sdram_clk_clk>), // sdram_clk.clk
		.sdram_addr    (<connected-to-sdram_addr>),    //     sdram.addr
		.sdram_ba      (<connected-to-sdram_ba>),      //          .ba
		.sdram_cas_n   (<connected-to-sdram_cas_n>),   //          .cas_n
		.sdram_cke     (<connected-to-sdram_cke>),     //          .cke
		.sdram_cs_n    (<connected-to-sdram_cs_n>),    //          .cs_n
		.sdram_dq      (<connected-to-sdram_dq>),      //          .dq
		.sdram_dqm     (<connected-to-sdram_dqm>),     //          .dqm
		.sdram_ras_n   (<connected-to-sdram_ras_n>),   //          .ras_n
		.sdram_we_n    (<connected-to-sdram_we_n>),    //          .we_n
		.ledr_export   (<connected-to-ledr_export>),   //      ledr.export
		.switch_export (<connected-to-switch_export>), //    switch.export
		.adc_sclk      (<connected-to-adc_sclk>),      //       adc.sclk
		.adc_cs_n      (<connected-to-adc_cs_n>),      //          .cs_n
		.adc_dout      (<connected-to-adc_dout>),      //          .dout
		.adc_din       (<connected-to-adc_din>),       //          .din
		.gpio_export   (<connected-to-gpio_export>)    //      gpio.export
	);

