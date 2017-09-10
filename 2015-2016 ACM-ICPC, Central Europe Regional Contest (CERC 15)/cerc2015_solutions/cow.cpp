// Author: Luka Kalinovcic
#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>

using namespace std;

#define MAX_COORDS 1000000

struct Vertical {
  int x, y1, y2;
  int weight;
  vector<Vertical*> children;
};

struct Horizontal {
  int y, x1, x2;
  int intersections;
  vector<Horizontal*> children;
};

struct Rectangle {
  int x1, y1, x2, y2;
  Vertical vertical;
  Horizontal horizontal;
};

vector<Rectangle> LoadRectangles() {
  int R;
  scanf("%d", &R);
  vector<Rectangle> rectangles(R);
  for (Rectangle& r : rectangles) {
    scanf("%d%d%d%d", &r.y1, &r.x1, &r.y2, &r.x2);
    r.vertical.x = r.x1 - 1;
    r.vertical.y2 = r.y1 - 1;
    r.vertical.weight = 0;
    r.horizontal.y = r.y2 + 1;
    r.horizontal.x1 = r.x1;
    r.horizontal.intersections = 0;
  }
  return rectangles;
}

vector<Vertical> LoadVerticalLeaves() {
  int V;
  scanf("%d", &V);
  vector<Vertical> leaves(V);
  for (Vertical& v : leaves) {
    scanf("%d%d", &v.y2, &v.x);
    v.weight = 1;
  }
  return leaves;
}

vector<Horizontal> LoadHorizontalLeaves() {
  int H;
  scanf("%d", &H);
  vector<Horizontal> leaves(H);
  for (Horizontal& h : leaves) {
    scanf("%d%d", &h.y, &h.x1);
    h.intersections = 0;
  }
  return leaves;
}

vector<Vertical*> MakeVerticalForest(vector<Rectangle>& rectangles,
                                     vector<Vertical>& leaves) {
  struct Event {
    int x;
    enum Type { kRectangleBegin, kVertical, kRectangleEnd } type;
    union {
      Vertical* vertical;
      Rectangle* rectangle;
    };
    Event(int x, Type type, Vertical* vertical)
        : x(x), type(type), vertical(vertical) {}
    Event(int x, Type type, Rectangle* rectangle)
        : x(x), type(type), rectangle(rectangle) {}
  };
  vector<Event> events;
  for (Vertical& v : leaves) {
    events.push_back(Event(v.x, Event::kVertical, &v));
  }
  for (Rectangle& r : rectangles) {
    events.push_back(Event(r.vertical.x, Event::kVertical, &r.vertical));
    events.push_back(Event(r.x1, Event::kRectangleBegin, &r));
    events.push_back(Event(r.x2, Event::kRectangleEnd, &r));
  }

  sort(events.begin(), events.end(),
      [](Event const& lt, Event const& rt) {
        if (lt.x != rt.x) return lt.x < rt.x;
        return lt.type < rt.type;
      });

  vector<Vertical*> roots;
  map<int, Rectangle*> active;
  for (Event const& e : events) {
    if (e.type == Event::kRectangleBegin) {
      active[e.rectangle->y1] = e.rectangle;
      active[e.rectangle->y2 + 1] = e.rectangle;
    }
    if (e.type == Event::kRectangleEnd) {
      active.erase(e.rectangle->y1);
      active.erase(e.rectangle->y2 + 1);
    }
    if (e.type == Event::kVertical) {
      map<int, Rectangle*>::iterator it = active.upper_bound(e.vertical->y2);
      if (it == active.begin()) {
        e.vertical->y1 = 0;
        roots.push_back(e.vertical);
      } else {
        Rectangle* r = (--it)->second;
        if (e.vertical->y2 <= r->y2) {
          e.vertical->y1 = r->y1;
          roots.push_back(e.vertical);
        } else {
          e.vertical->y1 = r->y2 + 1;
          r->vertical.children.push_back(e.vertical);
        }
      }
    }
  }
  return roots;
}

vector<Horizontal*> MakeHorizontalForest(vector<Rectangle>& rectangles,
                                         vector<Horizontal>& leaves) {
  struct Event {
    int y;
    enum Type { kRectangleBegin, kHorizontal, kRectangleEnd } type;
    union {
      Horizontal* horizontal;
      Rectangle* rectangle;
    };
    Event(int y, Type type, Horizontal* horizontal)
        : y(y), type(type), horizontal(horizontal) {}
    Event(int y, Type type, Rectangle* rectangle)
        : y(y), type(type), rectangle(rectangle) {}
  };
  vector<Event> events;
  for (Horizontal& h : leaves) {
    events.push_back(Event(h.y, Event::kHorizontal, &h));
  }
  for (Rectangle& r : rectangles) {
    events.push_back(Event(r.horizontal.y, Event::kHorizontal, &r.horizontal));
    events.push_back(Event(r.y1, Event::kRectangleBegin, &r));
    events.push_back(Event(r.y2, Event::kRectangleEnd, &r));
  }

  sort(events.begin(), events.end(),
      [](Event const& lt, Event const& rt) {
        if (lt.y != rt.y) return lt.y < rt.y;
        return lt.type < rt.type;
      });

  vector<Horizontal*> roots;
  map<int, Rectangle*> active;
  for (Event const& e : events) {
    if (e.type == Event::kRectangleBegin) {
      active[e.rectangle->x1 - 1] = e.rectangle;
      active[e.rectangle->x2] = e.rectangle;
    }
    if (e.type == Event::kRectangleEnd) {
      active.erase(e.rectangle->x1 - 1);
      active.erase(e.rectangle->x2);
    }
    if (e.type == Event::kHorizontal) {
      map<int, Rectangle*>::iterator it = active.lower_bound(e.horizontal->x1);
      if (it == active.end()) {
        e.horizontal->x2 = MAX_COORDS + 1;
        roots.push_back(e.horizontal);
      } else {
        Rectangle* r = it->second;
        if (e.horizontal->x1 >= r->x1) {
          e.horizontal->x2 = r->x2;
          roots.push_back(e.horizontal);
        } else {
          e.horizontal->x2 = r->x1 - 1;
          r->horizontal.children.push_back(e.horizontal);
        }
      }
    }
  }
  return roots;
}

class Fenwick {
 public:
  Fenwick(int n) : a_(n + 1, 0) {}
  void Update(int x, int delta) {
    for (int i = x + 1; i < a_.size(); i += i & -i) {
      a_[i] += delta;
    }
  }
  int Query(int x) {
    int ret = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
      ret += a_[i];
    }
    return ret;
  }
 private:
  vector<int> a_;
};

void ComputeIntersections(vector<Rectangle>& rectangles,
                          vector<Vertical>& vertical_leaves,
                          vector<Horizontal>& horizontal_leaves) {
  struct Event {
    int y;
    enum Type { kVerticalBegin, kHorizontal, kVerticalEnd } type;
    union {
      Vertical* vertical;
      Horizontal* horizontal;
    };
    Event(int y, Type type, Vertical* vertical)
        : y(y), type(type), vertical(vertical) {}
    Event(int y, Type type, Horizontal* horizontal)
        : y(y), type(type), horizontal(horizontal) {}
  };

  vector<Event> events;
  for (Vertical& v : vertical_leaves) {
    events.push_back(Event(v.y1, Event::kVerticalBegin, &v));
    events.push_back(Event(v.y2, Event::kVerticalEnd, &v));
  }
  for (Horizontal& h : horizontal_leaves) {
    events.push_back(Event(h.y, Event::kHorizontal, &h));
  }
  for (Rectangle& r : rectangles) {
    events.push_back(Event(r.vertical.y1, Event::kVerticalBegin, &r.vertical));
    events.push_back(Event(r.vertical.y2, Event::kVerticalEnd, &r.vertical));
    events.push_back(Event(r.horizontal.y, Event::kHorizontal, &r.horizontal));
  }

  sort(events.begin(), events.end(),
      [](Event const& lt, Event const& rt) {
        if (lt.y != rt.y) return lt.y < rt.y;
        return lt.type < rt.type;
      });

  Fenwick active_weights(MAX_COORDS + 2);
  for (Event const& e : events) {
    if (e.type == Event::kVerticalBegin) {
      active_weights.Update(e.vertical->x, e.vertical->weight);
    }
    if (e.type == Event::kVerticalEnd) {
      active_weights.Update(e.vertical->x, -e.vertical->weight);
    }
    if (e.type == Event::kHorizontal) {
      e.horizontal->intersections +=
          active_weights.Query(e.horizontal->x2) -
          active_weights.Query(e.horizontal->x1 - 1);
    }
  }
}

void ComputeWeight(Vertical* node) {
  for (Vertical* child : node->children) {
    ComputeWeight(child);
    node->weight += child->weight;
  }
}

void PropagateIntersections(Horizontal* node, int delta = 0) {
  node->intersections += delta;
  for (Horizontal* child : node->children) {
    PropagateIntersections(child, node->intersections);
  }
}

int main() {
  vector<Rectangle> rectangles = LoadRectangles();
  vector<Vertical> vertical_leaves = LoadVerticalLeaves();
  vector<Horizontal> horizontal_leaves = LoadHorizontalLeaves();

  vector<Vertical*> vertical_roots =
      MakeVerticalForest(rectangles, vertical_leaves);
  vector<Horizontal*> horizontal_roots =
      MakeHorizontalForest(rectangles, horizontal_leaves);

  for (Vertical* root : vertical_roots) {
    ComputeWeight(root);
  }
  ComputeIntersections(rectangles, vertical_leaves, horizontal_leaves);
  for (Horizontal* root : horizontal_roots) {
    PropagateIntersections(root);
  }
  for (Horizontal& leaf : horizontal_leaves) {
    printf("%d\n", leaf.intersections);
  }
  return 0;
}
