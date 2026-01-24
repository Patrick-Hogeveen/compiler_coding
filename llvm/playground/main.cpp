#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
 
using namespace llvm;

int main() {
    LLVMContext Context;
    auto M = std::unique_ptr<Module>(new Module("top", Context));

    auto *FT = FunctionType::get(Type::getInt32Ty(M->getContext()), false);
    auto *F = Function::Create(FT, Function::ExternalLinkage, "main", M.get());
    auto *block = BasicBlock::Create(M->getContext(), "MainEntry", F);

    IRBuilder<> Builder(block);
    Builder.CreateRet(Builder.getInt32(0));

    verifyModule(*M, &errs());
    M->print(outs(), nullptr);

    return 0;
}