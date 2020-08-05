[![Build status](https://ci.appveyor.com/api/projects/status/github/smartblade/bldmystery?branch=master)](https://ci.appveyor.com/project/smartblade/bldmystery)
[![Join the chat at https://gitter.im/BldMystery/community](https://badges.gitter.im/BldMystery/community.svg)](https://gitter.im/BldMystery/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Discord server](https://img.shields.io/badge/discord-join-7289DA.svg?logo=discord&longCache=true&style=flat)](https://discord.gg/VNgGP8x)


# Mystery of Blade
`Mystery of Blade` is a project containing decompiled source code of `Severance: Blade of Darkness` game
# Status
### Fully recovered binaries
- `Bladex.dll`
- `Netblade/Netblade.dll`
- `netgame.dll`
- `Raster.dll`
### Partially recovered binaries
- `Blade.exe`
# Method
- Create Visual Studio project with native `assembly` code of `Blade.exe`.
- Choose function/method which source code we want to reconstruct.
    - Provide `C++` implementation of this function/method.
    - Remove `assembly` implementation of this function (using `process_asm.py` script).
- Go to the next function/method.

So we have consistent project at each stage.
