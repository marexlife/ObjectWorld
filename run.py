from subprocess import run

run(["cmake", ".", "-B", "build"])
run(["cmake", "--build", "build"])
run(["./build/main/main"])