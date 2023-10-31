# include <cub3d.h>

int main(void)
{
    void *mlx; // The magical mlx pointer
    void *win; // The window pointer
    int width = 700;
    int height = 700;

    // Initialize mlx
    mlx = mlx_init();
    printf("A\n");
    // Create a window
    win = mlx_new_window(mlx, 800, 600, "Texture Printing Spell");
printf("A\n");
    // Load a texture image
    void *img = mlx_png_file_to_image(mlx, "cat.png", &width, &height);
printf("A\n");
    // Display the texture on the window
    mlx_put_image_to_window(mlx, win, img, 100, 100);
printf("A\n");
    // Your enchanted window awaits your further commands
printf("A\n");
    mlx_loop(mlx);

    return 0;
}
