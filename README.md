![CI](https://github.com/uw-pluverse/perses/actions/workflows/main.yml/badge.svg)

# Perses: Syntax-Directed Program Reduction

Perses is a language-agnostic program reducer to minimize a program with
respect to a set of constraints. It takes as input a program to reduce,
and a test script which specifies the constraints.
It outputs a minimized program which still satisfies the constraints specified
in the test script. Compared to Delta Debugging and Hierarchical Delta Debugging,
Perses leverages the syntax information in the Antlr grammar, and prunes the
search space by avoiding generating syntactically invalid programs.

### Supported Languages

Currently, Perses supports reduction for the following programming languages:

+ c: `*.c`
+ cpp: `*.cc`, `*.cpp`, `*.cxx`
+ glsl: `*.glsl`, `*.comp`, `*.frag`, `*.vert`
+ go: `*.go`
+ java: `*.java`
+ javascript: `*.javascript`, `*.js`
+ line: `*.line`
+ mysql: `*.mysql`
+ onetoken: `*.onetoken`
+ php: `*.php`
+ python3: `*.py`, `*.py3`
+ ruby: `*.rb`
+ rust: `*.rs`
+ scala: `*.scala`, `*.sc`
+ smtlibv2: `*.smt2`
+ solidity: `*.sol`
+ sqlite: `*.sqlite`
+ system_verilog: `*.v`, `*.sv`
+ xml: `*.xml`

Support for other languages is coming soon.

### Obtain and Run

There are three ways to obtain Perses.

- Download a prebuilt release JAR file from our [release page](https://github.com/perses-project/perses/releases),
  for example,

  ```bash
  wget https://github.com/uw-pluverse/perses/releases/download/v2.4/perses_deploy.jar
  java -jar perses_deploy.jar [options]? --test-script <test-script.sh> --input-file <program file>
  ```

- Clone the repo and build Perses from the source.

  ```bash
  git clone https://github.com/perses-project/perses.git
  cd perses
  bazelisk build //src/org/perses:perses_deploy.jar
  java -jar bazel-bin/src/org/perses/perses_deploy.jar [options]? \
      --test-script <test-script.sh> --input-file <program file>
  ```

- If you want to always use the trunk version of Perses, [perses-trunk](https://github.com/perses-project/perses/blob/master/scripts/perses-trunk) automatically downloads and builds the latest version.

  NOTE: [Bazelisk](https://github.com/bazelbuild/bazelisk) is the prerequisite to run perses-trunk successfully.

  ```bash
  wget https://raw.githubusercontent.com/perses-project/perses/master/scripts/perses-trunk
  chmod +x perses-trunk
  ./perses-trunk [options]? --test-script <test-script.sh> --input-file <program file>
  ```

#### Important Flags

- --test-script **&lt;test-script.sh&gt;**:
  The script encodes the constraints that both of the original program file and the reduced version should satisfy. It should return **0** if the constraints are satisfied.

- --input-file **&lt;program-file&gt;**: the program needs to be reduced. Currently, Perses
  supports C, Rust, Java and Go. Note that we can easily support any other languages,
  if the specific language can be parsed by an Antlr parser.

Check all available command line arguments

```bash
java -jar perses_deploy.jar  --help
```

The following is the complete list of command line arguments.

```
Usage: org.perses.Main [options]

[Inputs]  Options:
  * --test-script, --test, -t
      The test script to specify the property the reducer needs to preserve.
  * --input-file, --input, -i
      The input file to reduce
    --deps
      The dependency files required for running the property test
      Default: []

[Outputs]  Options:
    --output-dir, -o
      The output directory to save the reduced result.

[General Reduction Control]  Options:
    --fixpoint
      iterative reduction till fixpoint
      Default: true
    --threads
      Number of reduction threads: a positive integer, or 'auto'.
      Default: auto
    --code-format
      The format of the reduced program.
      Possible Values: [SINGLE_TOKEN_PER_LINE, ORIG_FORMAT, COMPACT_ORIG_FORMAT, PYTHON3_FORMAT, COMPACT_PYTHON3_FORMAT]
    --script-execution-timeout-in-seconds
      the interval in seconds to timeout the test script executions. the 
      default timeout is 600 seconds.
      Default: 600
    --script-execution-keep-waiting-after-timeout
      keep trying even after the script execution timeouts.
      Default: true

[Output Refining Control]  Options:
    --call-formatter
      call a formatter on the final result
      Default: false
    --format-cmd
      the command to format the reduced source file
      Default: <empty string>
    --call-creduce
      call C-Reduce when Perses is done.
      Default: false
    --creduce-cmd
      the C-Reduce command name or path
      Default: creduce

[Reduction Algorithm Control]  Options:
    --alg
      reduction algorithm: use --list-algs to list all available algorithms
    --list-algs
      list all the reduction algorithms.
    --enable-token-slicer
      Enable token slicer after syntax-guided reduction is done. Maybe slow.
      Default: false
    --enable-tree-slicer
      Enable tree slicer after syntax-guided reduction, and before token 
      slicer 
      Default: false
    --enable-line-slicer
      Enable line slicer after syntax-guided reduction, and before token 
      slicer 
      Default: false
    --default-delta-debugger-for-kleene
      The default delta debugger algorithm to reduce kleene nodes.
      Default: DFS
      Possible Values: [PRISTINE, PERSES_VARIANT_OF_PRISTINE, DFS, BFS, CDD, PROBDD, WDD, WPROBDD]

[Language Control]  Options:
    --list-langs
      List all the supported languages.
    --lang
      Specify the language of the program that is to be reduced.
      Default: <empty string>
    --parser-facade-class-name
      The parser facade to be used to parse the input program
      Default: <empty string>
    --list-parser-facades
      List all the available parser facades.
    --language-ext-jars
      A list of JAR files to support new languages
      Default: []

[Vulcan Reducer Control]  Options:
    --enable-vulcan
      Enable vulcan (using auxiliary reducers to help produce smaller 
      reduction output).
      Default: false
    --non-deletion-iteration-limit
      The maximum number of continuous non-deletion iterations allowed.
      Default: 10
    --window-size
      The window size used to perform local exhaustive pattern reduction.
      Default: 4
    --vulcan-fixpoint
      Enable vulcan fixpoint iteratively using auxiliary reducers until no 
      progress can be made
      Default: false

[T-Rec Reducer Control]  Options:
    --enable-trec
      enable T-Rec (a lexical-syntax guided fine-grained reduction process to 
      reduce and canonicalize each token)
      Default: false

[Profiling]  Options:
    --progress-dump-file
      The file to record the reduction process. The dump file can be large..
    --append-to-progress-dump-file
      Whether to append the reduction progress to the progress dump file
      Default: true
    --stat-dump-file
      The file to save the statistics collected during reduction.
    --profile-query-cache-time
      The file to save the profiling data of the query cache.
    --profile-query-cache-time-csv
      The file to save the profiling data of the query cache in the CSV 
      format. 
    --profile-query-cache-memory
      The file to save the profiling data of the query cache.
    --profile-actionset
      The file to save information of all the created edit action sets.
    --profile-delta-debugger
      The file to save the reduction process of the delta debugger.

[Cache Control]  Options:
    --query-caching
      Enable query caching for test script executions.
      Default: AUTO
      Possible Values: [TRUE, FALSE, AUTO]
    --query-cache-type
      the algorithm of the query cache
      Default: CONTENT_SHA512
      Possible Values: [AUTO, COMPACT_QUERY_CACHE, COMPACT_QUERY_CACHE_FORMAT_SENSITIVE, PERSES_FAST_LINEAR_SCAN_NO_COMPRESSION, PERSES_LEXEME_ID, CONFIG_BASED, ORIG_CONTENT_STRING_BASED, CONTENT_LEXEME_LIST_BASE, CONTENT_SHA512, CONTENT_SHA512_FORMAT, CONTENT_ZIP, RCC_MEM_LIT]
    --enable-lightweight-refreshing
      Whether to enable lightweight refreshing
      Default: true

[LPR Reducer Control]  Options:
    --enable-lpr
      Enable LPR (LLM-based transformations to improve reduction results).
      Default: false
    --lpr-fixpoint
      Enable lpr fixpoint. Everytime a transformation makes progress, go to 
      the next transformation.
      Default: false
    --llm-client-script
      The script to invoke LLM.

[Verbosity]  Options:
    --verbosity
      verbosity of logging
      Default: INFO
    --list-verbosity-levels
      list all verbosity levels

[Version]  Options:
    --version
      print the version

[Help]  Options:
    -h, --help
      print help message

```

### License

GNU General Public License 3.

### Publication 

This repository contains the implementations of the techniques proposed in the following papers.

#### 1. Perses: Syntax-Guided Program Reduction (ICSE 2018, [pdf](./doc/publication/2018_perses_icse.pdf))

```
@inproceedings{perses,
  author = {Sun, Chengnian and Li, Yuanbo and Zhang, Qirun and Gu, Tianxiao and Su, Zhendong},
  title = {Perses: Syntax-Guided Program Reduction},
  year = {2018},
  publisher = {Association for Computing Machinery},
  doi = {10.1145/3180155.3180236},
  booktitle = {Proceedings of the 40th International Conference on Software Engineering},
  pages = {361–371},
}
```

##### 2. Pushing the Limit of 1-Minimality of Language-Agnostic Program Reduction (OOPSLA 2023, [pdf](./doc/publication/2023_vulcan_oopsla.pdf))

```
@article{perses-vulcan,
  title={Pushing the Limit of 1-Minimality of Language-Agnostic Program Reduction},
  author={Xu, Zhenyang and Tian, Yongqiang and Zhang, Mengxiao and Zhao, Gaosen and Jiang, Yu and Sun, Chengnian},
  journal={Proceedings of the ACM on Programming Languages},
  volume={7},
  number={OOPSLA1},
  pages={636--664},
  year={2023},
  publisher={ACM New York, NY, USA}
}
```

##### 3. PPR: Pairwise Program Reduction (ESEC/FSE 2023, [pdf](./doc/publication/2023_ppr_fse.pdf), [doc](./ppr/README.md))

```
@inproceedings{perses-ppr,
  title={PPR: Pairwise Program Reduction},
  author={Zhang, Mengxiao and Xu, Zhenyang and Tian, Yongqiang and Jiang, Yu and Sun, Chengnian},
  booktitle={Proceedings of the 31st ACM Joint European Software Engineering Conference and Symposium on the Foundations of Software Engineering},
  pages={338--349},
  year={2023}
}
```

##### 4. On the Caching Schemes to Speed Up Program Reduction (TOSEM, [pdf](./doc/publication/2023_caching_tosem.pdf))

```
@article{perses-caching,
  title={On the Caching Schemes to Speed Up Program Reduction},
  author={Tian, Yongqiang and Zhang, Xueyan and Dong, Yiwen and Xu, Zhenyang and Zhang, Mengxiao and Jiang, Yu and Cheung, Shing-Chi and Sun, Chengnian},
  journal={ACM Transactions on Software Engineering and Methodology},
  volume={33},
  number={1},
  pages={1--30},
  year={2023},
  publisher={ACM New York, NY, USA}
}
```

##### 5. LPR: Large language models-aided program reduction (ISSTA 2024, [pdf](./doc/publication/2024_lpr_issta.pdf))

```
@inproceedings{perses-lpr,
  title={LPR: Large Language Models-Aided Program Reduction},
  author={Zhang, Mengxiao and Tian, Yongqiang and Xu, Zhenyang and Dong, Yiwen and Tan, Shin Hwei and Sun, Chengnian},
  booktitle={Proceedings of the 33rd ACM SIGSOFT International Symposium on Software Testing and Analysis},
  pages={261--273},
  year={2024}
}
```

##### 6. T-Rec: Fine-Grained Language-Agnostic Program Reduction Guided by Lexical Syntax (TOSEM, [pdf](./doc/publication/2024_trec_tosem.pdf))

```
@article{perses-trec,
  title={T-Rec: Fine-Grained Language-Agnostic Program Reduction Guided by Lexical Syntax},
  author={Xu, Zhenyang and Tian, Yongqiang and Zhang, Mengxiao and Zhang, Jiarui and Liu, Puzhuo and Jiang, Yu and Sun, Chengnian},
  journal={ACM Transactions on Software Engineering and Methodology},
  year={2024},
  publisher={ACM New York, NY}
}
```

##### 7. WDD: Weighted Delta Debugging (ICSE, [pdf](./doc/publication/2025_wdd_icse.pdf))

```
@article{perses-wdd,
  title={WDD: Weighted Delta Debugging},
  author={Zhou, Xintong and Xu, Zhenyang and Zhang, Mengxiao and Tian, Yongqiang and Sun, Chengnian},
  booktitle={Proceedings of the 47th International Conference on Software Engineering},
  year={2025},
  doi = {10.1109/ICSE55347.2025.00071},
  publisher = {IEEE Computer Society},
}
```

##### 8. Toward a Better Understanding of Probabilistic Delta Debugging (ICSE, [pdf](./doc/publication/2025_cdd_icse.pdf))

```
@article{perses-cdd,
  title={Toward a Better Understanding of Probabilistic Delta Debugging},
  author={Zhou, Xintong and Xu, Zhenyang and Zhang, Mengxiao and Tian, Yongqiang and Sun, Chengnian},
  booktitle={Proceedings of the 47th International Conference on Software Engineering},
  year={2025},
  doi = {10.1109/ICSE55347.2025.00117},
  publisher = {IEEE Computer Society},
}
```
