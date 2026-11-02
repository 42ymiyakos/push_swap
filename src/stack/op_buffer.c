// 命令バッファ: 実行した操作を ctx->ops に溜める
// op_buffer_add      : 末尾に追加 (足りなければ拡張)
// op_buffer_optimize : ra+rb → rr, pa+pb の打ち消しなどで手数を削減
// op_buffer_flush    : まとめて1回の write で stdout へ出力
