# 数据文件定义

## 天线参数

此项一共八条 格式类型为

```c++
AntennaEntry { parameter_: std::array<std::optional<double>> }
```

文件格式为

```text
[Metadata][parameter[0]][parameter[1]]...[parameter[7]]
```

- `Metadata` 大小为1Byte 每bit对应数组中的一项 0代表其对应相为空 1代表其对应相不为空
- `parameter[n]` 大小为8Byte 用于存放double类型的数据
