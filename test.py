import pygame

pygame.init()

WIDTH, HEIGHT = 800, 600
BALL_SIZE = 20
PADDLE_WIDTH, PADDLE_HEIGHT = 10, 100
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pong")

ball_x, ball_y = WIDTH // 2, HEIGHT // 2
ball_dx, ball_dy = 4, 4

paddle1_x, paddle1_y = 20, HEIGHT // 2 - PADDLE_HEIGHT // 2
paddle2_x, paddle2_y = WIDTH - 30, HEIGHT // 2 - PADDLE_HEIGHT // 2
paddle_speed = 6

running = True
while running:
    pygame.time.delay(15)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w] and paddle1_y > 0:
        paddle1_y -= paddle_speed
    if keys[pygame.K_s] and paddle1_y < HEIGHT - PADDLE_HEIGHT:
        paddle1_y += paddle_speed
    if keys[pygame.K_UP] and paddle2_y > 0:
        paddle2_y -= paddle_speed
    if keys[pygame.K_DOWN] and paddle2_y < HEIGHT - PADDLE_HEIGHT:
        paddle2_y += paddle_speed
    
    ball_x += ball_dx
    ball_y += ball_dy
    
    if ball_y <= 0 or ball_y >= HEIGHT - BALL_SIZE:
        ball_dy *= -1
    
    if (ball_x <= paddle1_x + PADDLE_WIDTH and paddle1_y < ball_y < paddle1_y + PADDLE_HEIGHT) or \
       (ball_x >= paddle2_x - BALL_SIZE and paddle2_y < ball_y < paddle2_y + PADDLE_HEIGHT):
        ball_dx *= -1
    
    if ball_x <= 0 or ball_x >= WIDTH:
        ball_x, ball_y = WIDTH // 2, HEIGHT // 2 
        ball_dx *= -1 
    
    screen.fill(BLACK)
    pygame.draw.rect(screen, WHITE, (paddle1_x, paddle1_y, PADDLE_WIDTH, PADDLE_HEIGHT))
    pygame.draw.rect(screen, WHITE, (paddle2_x, paddle2_y, PADDLE_WIDTH, PADDLE_HEIGHT))
    pygame.draw.ellipse(screen, WHITE, (ball_x, ball_y, BALL_SIZE, BALL_SIZE))
    pygame.display.update()

pygame.quit()
