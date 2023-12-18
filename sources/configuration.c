#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <configuration.h>
#include <effects.h>
#include <effects_data.h>

int get_trigger_config(const char *path, struct configuration *c) {
  // returns 0 on success
  // returns 1 if error in configuration file
  //  returns -1 if configuration file doesn't exist
  FILE   *fp;
  char   *line;
  int     lineNum = 0;
  size_t  len     = 0;
  ssize_t read;
  char    cfg[24]  = "--";
  char    effect[24]   = "--";
  int     read_cfg = -1, read_effect = -1;

  fp = fopen(path, "r");
  if (fp == NULL) return -1;
  while ((read = getline(&line, &len, fp)) != -1) {
    lineNum++;
    if (line[0] == '#' || line[0] == '\n') {
      continue;
    }

    if (sscanf(line, "%s %s", cfg, effect) == 2) {
      printf("Line %2d: Read trigger <%s> with effect <%s>\n", lineNum, cfg, effect);
    } else {
      // printf("Line %2d: Read trigger <%s> has no effect.\n", lineNum, cfg);
      strcpy(effect, "null-effect");
    }

    for (int i = 0; i < NUM_TOTAL_CONFIGS; i++) {
      if (!strcmp(cfg, configs[i])) {
        read_cfg = i;
        break;
      }
    }
    for (int j = 0; j < NUM_TOTAL_EFFECTS; j++) {
      if (!strcmp(effect, EFFECTS[j])) {
        read_effect = j;
        break;
      }
    }
    if (read_cfg == -1) {
      printf("Invalid config key %s in line %d of configuration file at %s\n", cfg,
             lineNum, path);
      return 1;
    }
    if (read_effect == -1) {
      printf("Invalid effect %s in line %d of configuration file at %s\n", effect,
             lineNum, path);
      return 1;
    }

    if (read_cfg >= NUM_TRIGGERS) {
      printf("Line %2d: flag <%s>(%d) was set.\n", lineNum, cfg, read_cfg);
    }

    switch (read_cfg) {
      case TRIGGER_CLICK_1: c->click1Effect     = read_effect; break;
      case TRIGGER_CLICK_2: c->click2Effect     = read_effect; break;
      case TRIGGER_CLICK_3: c->click3Effect     = read_effect; break;
      case TRIGGER_CLICK_4: c->click4Effect     = read_effect; break;
      case TRIGGER_CLICK_5: c->click5Effect     = read_effect; break;
      case TRIGGER_HOLD_1:  c->hold1Effect      = read_effect; break;
      case TRIGGER_HOLD_2:  c->hold2Effect      = read_effect; break;
      case TRIGGER_HOLD_3:  c->hold3Effect      = read_effect; break;
      case TRIGGER_HOLD_4:  c->hold4Effect      = read_effect; break;
      case TRIGGER_HOLD_5:  c->hold5Effect      = read_effect; break;
      case TRIGGER_LCLICK:  c->longClick1Effect = read_effect; break;
      case ASSUME_TB_OPEN:  c->assumeTBOpen     = 1          ; break;
    }
    strcpy(cfg, "--");
    strcpy(effect, "--");
    read_cfg = -1;
    read_effect  = -1;
  }
  fclose(fp);
  return 0;
}

void print_config(struct configuration *config) {
  printf("click1Effect: %x\n", config->click1Effect);
  printf("click2Effect: %x\n", config->click2Effect);
  printf("click3Effect: %x\n", config->click3Effect);
  printf("click4Effect: %x\n", config->click4Effect);
  printf("click5Effect: %x\n", config->click5Effect);
  printf("hold1Effect: %x\n", config->hold1Effect);
  printf("hold2Effect: %x\n", config->hold2Effect);
  printf("hold3Effect: %x\n", config->hold3Effect);
  printf("hold4Effect: %x\n", config->hold4Effect);
  printf("hold5Effect: %x\n", config->hold5Effect);
  printf("longClick1Effect: %x\n", config->longClick1Effect);
}
