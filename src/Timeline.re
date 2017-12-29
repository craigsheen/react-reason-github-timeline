open BsReactNative;

type state = { timelineItemsData: option(array(TimelineItemData.timelineItem)) };

type action =
  | Loaded(array(TimelineItemData.timelineItem));

let component = ReasonReact.reducerComponent("Timeline");

let make = (_children) => {
  ...component,
  initialState: () => {
    timelineItemsData: None
  },
  didMount: (self) => {
    let handleLoaded = self.reduce(timelineItemsData => Loaded(timelineItemsData));

      Js.Promise.(
        TimelineItemData.fetchTimelineItems()
        |> then_((timelineItemsData) => {
            handleLoaded(timelineItemsData);
            resolve();
        })
        |> ignore
      );
    ReasonReact.NoUpdate
  },
  reducer: (action, _state) => {
    switch action {
      | Loaded(timelineItemsData) => ReasonReact.Update({
          timelineItemsData: Some(timelineItemsData)
        })
    };
  },
  render: (self) => {
    let timelineItems =
      switch (self.state.timelineItemsData) {
      | Some(timelineItems) => ReasonReact.arrayToElement(
        Array.map(
          (timelineItem: TimelineItemData.timelineItem) => <TimelineItem key=timelineItem.id timelineItem=timelineItem />,
            timelineItems
          )
        )
      | None => <Text value="loading"/>
    };
    <ScrollView>
      (timelineItems)
    </ScrollView>
  }
};
