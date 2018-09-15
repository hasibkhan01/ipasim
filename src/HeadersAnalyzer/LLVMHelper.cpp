// LLVMHelper.cpp

#include "LLVMHelper.hpp"

#include "ErrorReporting.hpp"

#include <llvm/ADT/None.h>
#include <llvm/IR/Mangler.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>

using namespace llvm;
using namespace llvm::cl;
using namespace std;

LLVMInitializer::LLVMInitializer() {
  InitializeAllTargetInfos();
  InitializeAllTargets();
  InitializeAllTargetMCs();
  InitializeAllAsmPrinters();
}

void StringVector::loadConfigFile(StringRef File) {
  if (!readConfigFile(File, Saver, Vector)) {
    reportFatalError("couldn't load config file (" + File + ")");
  }
}

string LLVMHelper::mangleName(const Function &Func) {
  SmallString<16> Name;
  Mangler().getNameWithPrefix(Name, &Func,
                              /* CannotUsePrivateLabel */ false);
  return Name.str().str();
}

IRHelper::IRHelper(LLVMHelper &LLVM, const StringRef Name, const StringRef Path,
                   const StringRef Triple)
    : LLVM(LLVM), Builder(LLVM.Ctx), Module(Name, LLVM.Ctx) {

  // Get target from the triple provided.
  string Error;
  const Target *Target = TargetRegistry::lookupTarget(Triple, Error);
  if (!Target) {
    reportError("cannot create target");
    return;
  }

  // Create basic `TargetMachine`.
  TM.reset(Target->createTargetMachine(Triple, "generic", "", TargetOptions(),
                                       /* RelocModel */ None));

  // Configure LLVM `Module`.
  Module.setSourceFileName(Path);
  Module.setTargetTriple(Triple);
  Module.setDataLayout(TM->createDataLayout());
}

const char *const IRHelper::Windows32 = "i386-pc-windows-msvc";
const char *const IRHelper::Apple = "armv7s-apple-ios10";