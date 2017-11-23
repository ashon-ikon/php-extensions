# Writing PHP Extensions

This is an **Idiot's** guide to writing PHP Extensions.


### PHP Version
The primary target version for this project is PHP 7; while code may be backward-compatible, but consider checking official documentation from PHP on compatibility with earlier versions.

## Preamble
PHP (and the Zend Engine) is written in `C` langauge and thus a good working knowledge of `C` (and or `C++`) will be beneficial. While great effort has been take to ensure this guide can be followed from any OS platform, most of the command assumes `Bash` or `Sh` enviroment is available to work with.

This guide(s) borrow heavily from the official [PHP Extension hacker's guide](http://php.net/manual/en/internals2.php)

## Contents
- [x] Writing Simple PHP Extension in `C`
- [x] Use third party library within your PHP Extension
- [ ] Writing PHP Extension with `C++`


## Installing required packages
Depending on you distribution or Operating system you will need to install the following
* `git`
* `php-src`. `git clone https://github.com/php/php-src.git`
* `gcc 5`. Or equivalent
* Sane text editor. Sublime, GEdit, Vim, whatever
* **[See others...](http://php.net/manual/en/install.php)**

## Navigating through PHP-Src
PHP being a sophisticated and robust *application* written in `C language` is relies heavily on `C marco`'s. Sometimes you might wonder what any of these definitions are. See **[Internal Zend Api doc](http://php.net/manual/en/internals2.ze1.zendapi.php)** for more details.

#### Startup and Shutdown method
For more details about extension startup and shutdown methods [see](http://php.net/manual/en/internals2.ze1.zendapi.php#internals2.ze1.zendapi.tab.init-shutdown)

### Macro tricks
If ever found with guessing what a macro is, you can easily invoke this `grep` trick on the root tree of the `php-src` folder.
```bash
grep -r -E '\# *define +ZVAL_NEW_STR' $(pwd)
```


## Samples
Note, for starters, you should consider copying these codes to your `php-src/ext/` and compile from there till you grasp more concepts of how PHP works internally. Or at least a sym-link too could be handy.
`ln -svf samples/hello_world path/to/php-src/ext/hello_world` etc.

### Building extensions
Building the extension is mostly straightforwards but care needs to be take when attempting to compile the source for the for the first time.

```bash
buildconf --force # important to add `--force' for custom changes
./configure --enable-hello+world=shared
make
make check
```

* [Hello World](samples/hello_world/README.md)
* [Average function](samples/average/README.md)



## License
GNU GPL v2