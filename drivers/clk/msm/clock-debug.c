
static const struct file_operations clock_parent_fops = {
	.open		= simple_open,
	.read		= clock_parent_read,
	.write		= clock_parent_write,
};

#if defined(CONFIG_DEBUG_FS) && defined(CONFIG_COMMON_CLK_MSM)
void clk_debug_print_hw(struct clk *clk, struct seq_file *f)*f)
{
	void __iomem *base;
	struct clk_register_data *regs;
	u32 i, j, size;

	if (IS_ERR_OR_NULL(clk))
		return;

	clk_debug_print_hw(clk->parent, f);

	clock_debug_output(f, false, "%s\n", clk->dbg_name);

	if (!clk->ops->list_registers)
		return;

	j = 0;
	base = clk->ops->list_registers(clk, j, &regs, &size);
	while (!IS_ERR(base)) {
		for (i = 0; i < size; i++) {
			u32 val = readl_relaxed(base + regs[i].offset);
			clock_debug_output(f, false, "%20s: 0x%.8x\n",
						regs[i].name, val);
		}
		j++;
		base = clk->ops->list_registers(clk, j, &regs, &size);
	}
}

static int print_hw_show(struct seq_file *m, void *unused)
{
	struct clk *c = m->private;
	clk_debug_print_hw(c, m);

	return 0;
}

static int print_hw_open(struct inode *inode, struct file *file)
{
	return single_open(file, print_hw_show, inode->i_private);
}

static const struct file_operations clock_print_hw_fops = {
	.open		= print_hw_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= seq_release,
};


static void clock_measure_add(struct clk *clock)
{
	if (IS_ERR_OR_NULL(measure))
		return;

	if (clk_set_parent(measure, clock))
		return;

	debugfs_create_file("measure", S_IRUGO, clock->clk_dir, clock,
				&clock_measure_fops);
}
#endif