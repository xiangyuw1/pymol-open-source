

### 1. 清理旧构建缓存

```powershell
Remove-Item -Recurse -Force build\temp.win-amd64-cpython-312 -ErrorAction SilentlyContinue
```

### 2. 重新运行编译脚本

```powershell
cmd /c build_pymol.bat
```

或者整合成一行：

```powershell
Remove-Item -Recurse -Force build\temp.win-amd64-cpython-312 -ErrorAction SilentlyContinue; cmd /c build_pymol.bat
```

就这些。`build_pymol.bat` 已经包含了所有配置（VS 环境、CMake 路径、vcpkg 依赖、pip 安装参数），不需要额外操作。
