	component niosiisystem is
		port (
			clk_clk       : in    std_logic                     := 'X';             -- clk
			reset_reset   : in    std_logic                     := 'X';             -- reset
			sdram_clk_clk : out   std_logic;                                        -- clk
			sdram_addr    : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_ba      : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_cas_n   : out   std_logic;                                        -- cas_n
			sdram_cke     : out   std_logic;                                        -- cke
			sdram_cs_n    : out   std_logic;                                        -- cs_n
			sdram_dq      : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_dqm     : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_ras_n   : out   std_logic;                                        -- ras_n
			sdram_we_n    : out   std_logic;                                        -- we_n
			ledr_export   : out   std_logic_vector(9 downto 0);                     -- export
			switch_export : in    std_logic_vector(9 downto 0)  := (others => 'X'); -- export
			adc_sclk      : out   std_logic;                                        -- sclk
			adc_cs_n      : out   std_logic;                                        -- cs_n
			adc_dout      : in    std_logic                     := 'X';             -- dout
			adc_din       : out   std_logic;                                        -- din
			gpio_export   : out   std_logic_vector(15 downto 0)                     -- export
		);
	end component niosiisystem;

	u0 : component niosiisystem
		port map (
			clk_clk       => CONNECTED_TO_clk_clk,       --       clk.clk
			reset_reset   => CONNECTED_TO_reset_reset,   --     reset.reset
			sdram_clk_clk => CONNECTED_TO_sdram_clk_clk, -- sdram_clk.clk
			sdram_addr    => CONNECTED_TO_sdram_addr,    --     sdram.addr
			sdram_ba      => CONNECTED_TO_sdram_ba,      --          .ba
			sdram_cas_n   => CONNECTED_TO_sdram_cas_n,   --          .cas_n
			sdram_cke     => CONNECTED_TO_sdram_cke,     --          .cke
			sdram_cs_n    => CONNECTED_TO_sdram_cs_n,    --          .cs_n
			sdram_dq      => CONNECTED_TO_sdram_dq,      --          .dq
			sdram_dqm     => CONNECTED_TO_sdram_dqm,     --          .dqm
			sdram_ras_n   => CONNECTED_TO_sdram_ras_n,   --          .ras_n
			sdram_we_n    => CONNECTED_TO_sdram_we_n,    --          .we_n
			ledr_export   => CONNECTED_TO_ledr_export,   --      ledr.export
			switch_export => CONNECTED_TO_switch_export, --    switch.export
			adc_sclk      => CONNECTED_TO_adc_sclk,      --       adc.sclk
			adc_cs_n      => CONNECTED_TO_adc_cs_n,      --          .cs_n
			adc_dout      => CONNECTED_TO_adc_dout,      --          .dout
			adc_din       => CONNECTED_TO_adc_din,       --          .din
			gpio_export   => CONNECTED_TO_gpio_export    --      gpio.export
		);

