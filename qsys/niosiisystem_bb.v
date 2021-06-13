
module niosiisystem (
	clk_clk,
	reset_reset,
	sdram_clk_clk,
	sdram_addr,
	sdram_ba,
	sdram_cas_n,
	sdram_cke,
	sdram_cs_n,
	sdram_dq,
	sdram_dqm,
	sdram_ras_n,
	sdram_we_n,
	ledr_export,
	switch_export,
	adc_sclk,
	adc_cs_n,
	adc_dout,
	adc_din,
	gpio_export);	

	input		clk_clk;
	input		reset_reset;
	output		sdram_clk_clk;
	output	[12:0]	sdram_addr;
	output	[1:0]	sdram_ba;
	output		sdram_cas_n;
	output		sdram_cke;
	output		sdram_cs_n;
	inout	[15:0]	sdram_dq;
	output	[1:0]	sdram_dqm;
	output		sdram_ras_n;
	output		sdram_we_n;
	output	[9:0]	ledr_export;
	input	[9:0]	switch_export;
	output		adc_sclk;
	output		adc_cs_n;
	input		adc_dout;
	output		adc_din;
	output	[15:0]	gpio_export;
endmodule
