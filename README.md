## WinApi++: A C++ wrapper for Windows API, for non-gui applications.

WinApi++ focuses to wrap the windows API for non-gui applications.



## Examples

```cpp
std::cout << winpp::env::expend("%USERPROFILE%") << endl;
std::cout << winpp::env::vars["%USERPROFILE%"] << endl;
```


## License

Licensed under either of
 * Apache License, Version 2.0 ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
 * MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)
at your option.

### Contribution

Unless you explicitly state otherwise, any contribution intentionally submitted
for inclusion in the work by you shall be dual licensed as above, without any
additional terms or conditions.