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
            flash: {
                command: "lime build flash"
            },
            android: {
               command: "lime build android"
            }/*,
            ios: {
                command: "lime build ios -simulator"
            }*/
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
                    "output/js/fluid.min.js": ["output/js/fluid.dev.js"]
                }
            }
        },
        browserify: {
            dist: {
                files: {
                    "output/js/fluid.js": ["output/js/fluid.dev.js"]
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