/**
 * Created by Adi Mora on 10/10/2014.
 */

module.exports = function (grunt) {

    grunt.initConfig({
        pkg: grunt.file.readJSON("package.json"),

        haxe: {
            project: {
                hxml: "build.hxml"
            }
        },

        exec: {
            command: "lime build flash"
        },

        uglify: {
            options: {
                mangle: true,
                beautify: true,
                drop_console: true,
                compress: true,
                sourceMap: true,
                report: "min",
                banner: "/*\n" +
                    " * <%= pkg.name %>\n" +
                    " * v<%= pkg.version %>\n" +
                    " * <%= grunt.template.today('yyyy-mm-dd') %>\n" +
                    " **/\n"
            },
            target: {
                files: {
                    "export/js/fluid.min.js": ["export/js/fluid.dev.js"]
                }
            }
        },
        browserify: {
            dist: {
                files: {
                    "export/js/fluid.js": ["export/js/fluid.dev.js"]
                }
            }
        }
    });

    grunt.loadNpmTasks("grunt-exec");
    grunt.loadNpmTasks("grunt-haxe");
    grunt.loadNpmTasks("grunt-contrib-uglify");
    grunt.loadNpmTasks("grunt-browserify");
    grunt.loadNpmTasks("grunt-contrib-copy");

    grunt.registerTask("default", ["haxe", "exec", "browserify", "uglify"]);

};