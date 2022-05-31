#include "station.h"

bool station::operator==(const station &other) const
{
  return name == other.name && line == other.line;
}

bool station::operator<(const station &other) const
{
  return name < other.name || (name == other.name && line < other.line);
}