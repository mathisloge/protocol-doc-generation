# protodoc

Generates protocol descrptions from https://github.com/commschamp/CommsDSL-Specification schema definition files.

## Usage

Create a protodoc.json file
```json
{
    "templates": {
        "root": "",
        "platforms": "platforms.adoc",
        "namespaces": "namespaces.adoc",
        "namespace": "namespaces.adoc"
    },
    "lang": "lang_en.json",
    "custom": "custom.json",
    "output": "D:/dev/commsdsl_text/asciidoc/gen",
    "trim": true,
    "split": true,
    "jsonOutput": true,
    "files": [
        "protos/myschema1.xml",
        "protos/myschema2.xml",
        "protos/myschema3.xml",
        "protos/myschema4.xml"
    ],
    "inputDir": "D:/dev/myschema/protos/",
    "responseFile": {
        "file": "myschema.txt",
        "path": "D:/dev/myschema/protos/"
    }
}
```
If a file path is relativ, the path will resolve to `<location of protodoc.json>/<filepath>`.

Note that only one of `files`, `inputDir` or `responseFile` can be present at a time.
I don't recommend the usage of `inputDir` since it will just read the files in the order of the filesystem. In most cases the commsdsl parser would fail because of missing defines.



| Json Field          | Description   | Required   |
| ------------------- | ------------- |----|
| templates           | ||
| templates/root      | the templates root dir.       |required|
| templates/platforms | name of the platforms template file with the correct extension      |required|
| templates/namespaces| name of the namespaces template file with the correct extension      |required|
| templates/namespace | name of the namespace template file with the correct extension      |required|
| lang                | File path to the language file. See [Language Json](#language-json)      |required|
| custom              | file path to the merge json file. See [Custom Json](#custom-json)      |optional|
| output              | output directory      |required|
| trim                | remove new line after a command |optional (default: false)|
| split               | remove whitespaces and tabs from the beginning to the start of a block |optional (default: false)|
| jsonOutput          | dump the generated json into a file `<output>/protodoc_internal.json`       |optional (default: false)|
| files               | A array of schema files.      | required (only on of `files`, `inputDir` or `responseFile`) |
| inputDir            | The directory containing the schema files     | required (only on of `files`, `inputDir` or `responseFile`) |
| responseFile        | A schemas_list.txt file as described in [commsdsl-wiki#selecting-schema-files](https://github.com/commschamp/commsdsl/blob/master/doc/Manual_commsdsl2comms.md#selecting-schema-files)     | required (only on of `files`, `inputDir` or `responseFile`) |
| responseFile/file   | the file path to the schema file      | required |
| responseFile/path   | the file path which gets prepended to every file in the schema list file. Can be empty.      | required |


## Language Json
This file contains hardcoded language strings for types and units (if used)

## Custom Json

This file will get merged into the json file. If you need custom text inside of your templates, you can add this on this way. Also you could easily overwrite generated json values.
I recommend to dump the generated json values with `jsonOutput: true` to match the correct keys you want to override.



## Templates

Please see https://pantor.github.io/inja for detailed instructions of the template language.

### Available Functions

In addition to the buildin inja function, the following functions are provided: 

| Function            | Description     | 
| ------------------- | ------------- |
| latexText(string) | converts a string to a latex compitable string. E.g. `\textit{my_file}` will get converted to `\textit{my\_file}` | 
| sortEnum(object: enumfield, string: sortfield) | will output a array with the enum field keys sorted in ascending order of `sortfield`|

If you need additional functions, please open a feature request issue.
