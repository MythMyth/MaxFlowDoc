Bài toán max flow:
https://www.geeksforgeeks.org/max-flow-problem-introduction/

Bài toán min cut:
https://www.geeksforgeeks.org/minimum-cut-in-a-directed-graph/

Thuật toán fulkerson:
https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/

Thuật toán Dinc:
https://www.geeksforgeeks.org/dinics-algorithm-maximum-flow/

- Max flow của đồ thị chính là tổng weight của min cut
- Các bước giải bài sử dụng max flow:
	+ Đánh giá bài toán có yếu tố "phân bổ 1 lượng tài nguyên hữu hạn" hay không
	+ Nếu có, "tài nguyên" cần phân bổ sẽ đóng vai trò là "nước" trong bài toán max flow cơ bản, từ thông tin của
	đề bài, xây dựng đồ thị, có thể thêm 2 node source, sink nếu cần
	+ Đánh giá min cut của đồ thị đã thành lập sẽ gồm những thành phần nào, các thành phần này có liên quan gì tới
	yêu cầu cuối cùng
	+ Đánh giá đồ thị thặng dư hình thành sau khi chạy thuật toán có liên quan gì tới yêu cầu cuối cùng
	+ Xây dựng công thức tính toán kết quả dựa vào 2 đánh giá kể trên
	+ Triển khai thuật toán
