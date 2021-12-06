const {argv} = process;
const argc = process.argv.length;

if (argc <= 2) {

    console.log("Komodo Interpreter Version 0.0.1")
    console.log()
    console.log("Usage:")
    console.log("   kom <file_path>")
}

const entryPointFileName = argv[3]

const program = new Program(entryPointFileName);

program.simulate();
