module helloworldfpga(
	input wire x,
	output wire y,
	output wire cl
);
reg p,q;
reg d1,d2;
initial begin
p = 0;
q = 0;
end
reg [28:0] delay;
wire clk;
reg mclk;
qlal4s3b_cell_macro u_qlal4s3b_cell_macro (
	.Sys_Clk0 (clk),
);
always @(posedge clk) begin
	delay = delay+1;
	if(delay>40000000) begin
	mclk = !mclk;
	delay = 0;
	end
end
always @(negedge mclk) begin
	d1 = (q&&!x);
	d2 = (x);
	y = (p&&x);
end
always @(posedge mclk) begin
	p = d1;
	q = d2;
end
assign cl = mclk;
endmodule
