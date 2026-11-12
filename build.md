

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

### 3. 在 Git Bash / MINGW 里运行

`/c` 会被 MSYS 当成路径转换成 `C:\`，导致 `cmd` 只是打开又退出、构建根本没执行（日志里只有 cmd 横幅）。必须加前缀：

```bash
MSYS_NO_PATHCONV=1 cmd.exe /c build_pymol.bat
```

或者在 bash 里用双斜杠：`cmd //c build_pymol.bat`。

就这些。`build_pymol.bat` 已经包含了所有配置（VS 环境、CMake 路径、vcpkg 依赖、pip 安装参数），不需要额外操作。

### 附：可选组件所需 vcpkg 包

`vcpkg.exe` 在 `C:\vcpkg\vcpkg.exe`（未加入 PATH），用绝对路径调用：

| 组件 | vcpkg 包 | pip 参数 |
|---|---|---|
| glTF 2.0 / GLB 导出 | `nlohmann-json` | `--config-settings json=true` |
| OpenVR | `openvr` | `--config-settings openvr=true` |
| VTK-m 等值面 | `vtk-m` | `--config-settings use-vtkm=2.x` |

```powershell
C:\vcpkg\vcpkg.exe install nlohmann-json:x64-windows-static
```
