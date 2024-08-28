// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once

// Autocorrection dictionary (10 entries):
//   :guage     -> gauge
//   :the:the:  -> the
//   accomodate -> accommodate
//   acommodate -> accommodate
//   apparrent  -> apparent
//   cieling    -> ceiling
//   concensus  -> consensus
//   gaurantee  -> guarantee
//   recieve    -> receive
//   seperate   -> separate

#define AUTOCORRECT_MIN_LENGTH 6 // ":guage"
#define AUTOCORRECT_MAX_LENGTH 10 // "accomodate"
#define DICTIONARY_SIZE 185

static const uint8_t autocorrect_data[DICTIONARY_SIZE] PROGMEM = {
    0x6C, 0x10, 0x00, 0x08, 0x1B, 0x00, 0x0A, 0x8B, 0x00, 0x16, 0x9A, 0x00, 0x17, 0xAB, 0x00, 0x00,
    0x08, 0x0B, 0x17, 0x2C, 0x08, 0x0B, 0x17, 0x2C, 0x00, 0x84, 0x00, 0x48, 0x28, 0x00, 0x0A, 0x3A,
    0x00, 0x17, 0x45, 0x00, 0x19, 0x7F, 0x00, 0x00, 0x17, 0x11, 0x04, 0x15, 0x18, 0x04, 0x0A, 0x00,
    0x87, 0x75, 0x61, 0x72, 0x61, 0x6E, 0x74, 0x65, 0x65, 0x00, 0x04, 0x18, 0x0A, 0x2C, 0x00, 0x83,
    0x61, 0x75, 0x67, 0x65, 0x00, 0x04, 0x00, 0x47, 0x4E, 0x00, 0x15, 0x73, 0x00, 0x00, 0x12, 0x10,
    0x00, 0x50, 0x58, 0x00, 0x12, 0x67, 0x00, 0x00, 0x12, 0x06, 0x04, 0x00, 0x87, 0x63, 0x6F, 0x6D,
    0x6D, 0x6F, 0x64, 0x61, 0x74, 0x65, 0x00, 0x06, 0x06, 0x04, 0x00, 0x84, 0x6D, 0x6F, 0x64, 0x61,
    0x74, 0x65, 0x00, 0x08, 0x13, 0x08, 0x16, 0x00, 0x84, 0x61, 0x72, 0x61, 0x74, 0x65, 0x00, 0x08,
    0x0C, 0x06, 0x08, 0x15, 0x00, 0x83, 0x65, 0x69, 0x76, 0x65, 0x00, 0x11, 0x0C, 0x0F, 0x08, 0x0C,
    0x06, 0x00, 0x85, 0x65, 0x69, 0x6C, 0x69, 0x6E, 0x67, 0x00, 0x18, 0x16, 0x11, 0x08, 0x06, 0x11,
    0x12, 0x06, 0x00, 0x85, 0x73, 0x65, 0x6E, 0x73, 0x75, 0x73, 0x00, 0x11, 0x08, 0x15, 0x15, 0x04,
    0x13, 0x13, 0x04, 0x00, 0x83, 0x65, 0x6E, 0x74, 0x00
};
