#include <iostream>
#include <torch/torch.h>
#include <armadillo>
#include <chrono>

// Benchmark function
template<typename Func>
double benchmark(Func func, const std::string& description) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << description << " elapsed time: " << elapsed.count() << " seconds" << std::endl;
    return elapsed.count();
}

void benchmark_pytorch_cpu() {
    auto tensor1 = torch::rand({100, 100, 100}, torch::kCPU);
    auto tensor2 = torch::rand({100, 100, 100}, torch::kCPU);
    auto result = torch::matmul(tensor1, tensor2);  // Multiply tensors
}

void benchmark_pytorch_gpu() {
    auto tensor1 = torch::rand({100, 100, 100}, torch::kCUDA);
    auto tensor2 = torch::rand({100, 100, 100}, torch::kCUDA);
    auto result = torch::matmul(tensor1, tensor2);  // Multiply tensors
}

void benchmark_armadillo_cpu() {
    arma::cube matrix1 = arma::randu<arma::cube>(1000, 1000, 1000);
    arma::cube matrix2 = arma::randu<arma::cube>(1000, 1000, 1000);
    arma::cube result = matrix1 % matrix2;  // Element-wise multiplication
}

int main() {
    std::cout << "Benchmarking PyTorch (CPU)..." << std::endl;
    benchmark(benchmark_pytorch_cpu, "PyTorch CPU");

    std::cout << "Benchmarking PyTorch (GPU)..." << std::endl;
    benchmark(benchmark_pytorch_gpu, "PyTorch GPU");

    std::cout << "Benchmarking Armadillo (CPU)..." << std::endl;
    benchmark(benchmark_armadillo_cpu, "Armadillo CPU");
    
    return 0;
}
